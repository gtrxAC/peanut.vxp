// References:
// https://github.com/XimikBoda/RTXBlocksVxp/blob/main/RTXBlocksVxp/mainVxp.cpp
// https://github.com/raysan5/raylib/blob/master/src/rtext.c#L1483

#define PEANUT_GB_HEADER_ONLY
#include "common.h"

VMFILE log_file;
extern VMWCHAR ucs2_str[128];

void *gx_malloc(int size) {
    void *result = vm_malloc(size);
    if (!result) show_error_and_exit("Out of memory!");
    return result;
}

void log_init() {
    vm_ascii_to_ucs2(ucs2_str, 256, "e:\\peanutvxp\\log.txt");
    log_file = vm_file_open(ucs2_str, MODE_CREATE_ALWAYS_WRITE, 0);
}

void log_write(char *str) {
    int unused;
	vm_file_write(log_file, str, strlen(str), &unused);
	vm_file_write(log_file, "\n", 1, &unused);
	vm_file_commit(log_file);
}

void input_exit(VMINT state, VMWSTR text) {
	vm_exit_app();
}

void show_error_and_exit(const char* text) {
	vm_ascii_to_ucs2(ucs2_str, 256, (VMSTR)text);
	vm_input_text2(ucs2_str, 0, input_exit);
}

int read_from_file_to_addr(const char* path_, void** addr) {
	char path[128];
	sprintf(path, "e:\\peanutvxp\\%s", path_);
	vm_ascii_to_ucs2(ucs2_str, 256, (VMSTR)path);
	VMUINT red = 0, size = 0;

	VMFILE f = vm_file_open(ucs2_str, MODE_READ, 1);
	if (f < 0) {
		log_write("File not found");
		*addr = 0;
		return 0;
	}
	vm_file_getfilesize(f, &size);
	*addr = gx_malloc(size);
    if (!addr) return 0;
	vm_file_read(f, *addr, size, &red);
	vm_file_close(f);
	return size;
}

void write_from_addr_to_file(const char* path_, void* addr, int size) {
	char path[128];
	sprintf(path, "e:\\peanutvxp\\%s", path_);
	vm_ascii_to_ucs2(ucs2_str, 256, (VMSTR)path);
	VMUINT red = 0;

	VMFILE f = vm_file_open(ucs2_str, MODE_CREATE_ALWAYS_WRITE, 1);
	if (f < 0) {
		show_error_and_exit("File not found");
		return;
	}
	vm_file_write(f, addr, size, &red);
	vm_file_close(f);
}

// From raylib
// Replace text string
// REQUIRES: strlen(), strstr(), strncpy(), strcpy()
// WARNING: Allocated memory must be manually freed
char *TextReplace(char *text, const char *replace, const char *by)
{
    // Sanity checks and initialization
    if (!text || !replace || !by) return NULL;

    char *result = NULL;

    char *insertPoint = NULL;   // Next insert point
    char *temp = NULL;          // Temp pointer
    int replaceLen = 0;         // Replace string length of (the string to remove)
    int byLen = 0;              // Replacement length (the string to replace by)
    int lastReplacePos = 0;     // Distance between replace and end of last replace
    int count = 0;              // Number of replacements

    replaceLen = strlen(replace);
    if (replaceLen == 0) return NULL;  // Empty replace causes infinite loop during count

    byLen = strlen(by);

    // Count the number of replacements needed
    insertPoint = text;
    for (count = 0; (temp = strstr(insertPoint, replace)); count++) insertPoint = temp + replaceLen;

    // Allocate returning string and point temp to it
    temp = result = (char *)gx_malloc(strlen(text) + (byLen - replaceLen)*count + 1);

    if (!result) return NULL;   // Memory could not be allocated

    // First time through the loop, all the variable are set correctly from here on,
    //  - 'temp' points to the end of the result string
    //  - 'insertPoint' points to the next occurrence of replace in text
    //  - 'text' points to the remainder of text after "end of replace"
    while (count--)
    {
        insertPoint = strstr(text, replace);
        lastReplacePos = (int)(insertPoint - text);
        temp = strncpy(temp, text, lastReplacePos) + lastReplacePos;
        temp = strcpy(temp, by) + byLen;
        text += lastReplacePos + replaceLen; // Move to next "end of replace"
    }

    // Copy remaind text part after replacement to result (pointed by moving temp)
    strcpy(temp, text);

    return result;
}