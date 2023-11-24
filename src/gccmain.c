#include <stdio.h>
#include "vmsys.h"
#include "vmchset.h"
#include "vmlog.h"
#include "vmio.h"
#include "vmstdlib.h"

extern unsigned int __init_array_start;
extern unsigned int __init_array_end;

typedef VMINT(*vm_get_sym_entry_t)(char* symbol);
vm_get_sym_entry_t vm_get_sym_entry;
typedef void (**__init_array) (void);

int __g_errno = 0;

void* malloc(size_t size)
{
	return vm_malloc(size);
}

void* calloc(size_t number, size_t size)
{
	return vm_calloc(size * number);
}

void* realloc(void* ptr, size_t newsize) {
	return vm_realloc(ptr, newsize);
}

void free(void* ptr)
{
	vm_free(ptr);
}

void* _calloc_r(struct _reent* unused, size_t count, size_t size)
{
	(void)unused;
	void* ret = calloc(count, size);
	return ret;
}

//void __cxa_pure_virtual()
//{
//	while (1);
//}

//int __cxa_guard_acquire(int* p)
//{
//	return 1;
//}
//
//void __cxa_guard_release(int* p)
//{
//	return;
//}

//int* __errno()
//{
//	return &__g_errno;
//}

void gcc_entry(unsigned int entry, unsigned int init_array_start, unsigned int count)
{
	unsigned int i;
	__init_array ptr;
	vm_get_sym_entry = (vm_get_sym_entry_t)entry;

	if (init_array_start == 0)
		init_array_start = (unsigned int)&__init_array_start,
		count = ((unsigned int)&__init_array_end - (unsigned int)&__init_array_start) / 4;

	ptr = (__init_array)init_array_start;
	for (i = 1; i < count; i++)
	{
		ptr[i]();
	}
	vm_main();
}
