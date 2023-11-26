// Reference:
// https://github.com/XimikBoda/RTXBlocksVxp/blob/main/RTXBlocksVxp/mainVxp.cpp

#include "vmsys.h"
#include "vmio.h"
#include "vmgraph.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "vmtimer.h"
#include "vm4res.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

VMFILE log_file;

void log_init() {
    VMWCHAR s[50];
    vm_gb2312_to_ucs2(s, 50, "e:\\peanutvxp\\log.txt");
    log_file = vm_file_open(s, MODE_CREATE_ALWAYS_WRITE, 0);
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
	VMWCHAR wstr[200];
	vm_gb2312_to_ucs2(wstr, 200, (VMSTR)text);
	vm_input_text2(wstr, 0, input_exit);
}

int read_from_file_to_addr(const char* path_, void** addr) {
	char path[200];
	sprintf(path, "e:\\peanutvxp\\%s", path_);
	VMWCHAR wstr[200];
	vm_gb2312_to_ucs2(wstr, 400, (VMSTR)path);
	VMUINT red = 0, size = 0;

	VMFILE f = vm_file_open(wstr, MODE_READ, 1);
	if (f < 0) {
		char tmp[100] = "";
		// sprintf("%s not found", path);
		show_error_and_exit("File not found");
		*addr = 0;
		return 0;
	}
	vm_file_getfilesize(f, &size);
	*addr = malloc(size);
	vm_file_read(f, *addr, size, &red);
	vm_file_close(f);
	return size;
}

void write_from_addr_to_file(const char* path_, void* addr, int size) {
	char path[200];
	sprintf(path, "e:\\peanutvxp\\%s", path_);
	VMWCHAR wstr[200];
	vm_gb2312_to_ucs2(wstr, 400, (VMSTR)path);
	VMUINT red = 0;

	VMFILE f = vm_file_open(wstr, MODE_CREATE_ALWAYS_WRITE, 1);
	if (f < 0) {
		show_error_and_exit("File not found");
		return;
	}
	vm_file_write(f, addr, size, &red);
	vm_file_close(f);
}