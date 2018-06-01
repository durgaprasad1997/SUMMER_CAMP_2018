
#include<malloc.h>
#include"SimpleH.h"

#define  MAX_SIZE 1024;
int current = -1;
void *myMemory;

struct FreeSize
{
	int address;
	int size;
	struct FreeSize *next;
};
struct FreeSize *head=NULL;
struct FreeSize *currentPos=head;


void freeList(int memory,int size)
{
	if (head == NULL)
	{
		head = (struct FreeSize *)malloc(sizeof(struct FreeSize));

		head->next = NULL;
		currentPos = head;
	}
	struct FreeSize *newnode = (struct FreeSize *)malloc(sizeof(struct FreeSize));
	newnode->next = NULL;
	newnode->address = memory;
	newnode->size = size;

	currentPos->next = newnode;
	currentPos = newnode;

}

void deleteFreeSpace(struct FreeSize * t)
{
	struct FreeSize * headtemp = head;
	if (headtemp == t)
	{
		head = NULL;
		currentPos = NULL;
	}
	struct FreeSize *previous = headtemp;
	while (headtemp->next != NULL)
	{
		if (headtemp == t)
		{
			previous->next = headtemp->next;
			return;
		}
		previous = headtemp;
		headtemp = headtemp->next;
	}
	if (headtemp == t)
	{
		headtemp->next = NULL;
	}
}

int* getFreeSpace(int size)
{
	struct FreeSize *temp = head;
	while (temp != NULL)
	{
		if (temp->size >= size)
		{
			int add = temp->address;
			deleteFreeSpace(temp);
			return &add;
		}
		temp = temp->next;
	}
	return NULL;
}

void init()
{
	myMemory = (int *)malloc(1024);
	current = 0;
}

__declspec(dllexport) void* dp_malloc(int size)
{

	if (current == -1)
	{
		init();
	}

	int *temp;
	if ((temp=getFreeSpace(size)) != NULL)
	{
		/*temp = size;
		int next = 4;
		temp += next;
		next++;
		return (void *)(&temp + 1);
		*/
		int *x = temp;
		current = 0;
		x[current] = size;
		current += 4;
		x += current;
		//x += size;
		current++;
		//temp = (void *)x;
		return (void *)(x + 1);

	}
	else
	{
		int *x = (int *)myMemory;
		current = 0;
		x[current] = size;
		current += 4;
		x += current;
		//x += size;
		current++;
		myMemory = (void *)x;
		return (void *)(x + 1);
	}

}

__declspec(dllexport) void dp_free(void * mem)
{
	
	void*x = mem;

	int add1 = (int)x;
	int adjust = 4;
	int add =add1- adjust;
	

	printf("%d  %d ", add1, add);

	freeList(add1, add);
}

__declspec(dllexport) void dp_debug()
{

}
