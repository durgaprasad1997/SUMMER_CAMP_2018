#include <stdio.h>


struct node
{
	int address;
	int size;
	int byteStatus[4];
};

extern "C"
{
	__declspec(dllexport) void* dp_malloc(int );
	
	__declspec(dllexport) void dp_free(void *);

	__declspec(dllexport) void dp_debug();

	
}