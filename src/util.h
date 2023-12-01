#pragma once

void log_init();
void log_write(char *str);

void show_error_and_exit(const char* text);
int read_from_file_to_addr(const char* path_, void** addr);
void write_from_addr_to_file(const char* path_, void* addr, int size);

char *TextReplace(char *text, const char *replace, const char *by);

// MIN is already defined by peanut_gb.h
#define MAX(a, b) (((double) a) > ((double) b) ? (a) : (b))