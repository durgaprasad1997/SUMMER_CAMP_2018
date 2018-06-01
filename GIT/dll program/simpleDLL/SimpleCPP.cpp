
#include<malloc.h>
#include"SimpleH.h"

int MAX_SIZE=1024;
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
	if (headtemp->address== t->address)
	{
		head = NULL;
		currentPos = NULL;
		return;
	}
	struct FreeSize *previous = headtemp;
	while (headtemp->next != NULL)
	{
		if (headtemp->address == t->address)
		{
			previous->next = headtemp->next;
			return;
		}
		previous = headtemp;
		headtemp = headtemp->next;
	}
	if (headtemp->address == t->address)
	{
		headtemp->next = NULL;
	}
}

int getFreeSpace(int size)
{
	struct FreeSize *temp = head;
	while (temp != NULL)
	{
		if (temp->size >= size)
		{
			int add = temp->address;
			deleteFreeSpace(temp);
			return add;
		}
		temp = temp->next;
	}
	return -1000;
}

void init()
{
	myMemory = (int *)malloc(MAX_SIZE);
	current = 0;
}

__declspec(dllexport) void* dp_malloc(int size)
{

	if (current == -1)
	{
		init();
	}

	int temp;
	if ((temp=getFreeSpace(size)) !=-1000)
	{
	
		int *x = &temp;
		current = 0;
		x[current] = size;
		current += 4;
		x += current;
		
		current++;
		
		return (void *)(x + 1);

	}
	else
	{
		int *x = (int *)myMemory;
		current = 0;
		x[current] = size;
		current += 4;
		x += current;
		
		current++;
		myMemory = (void *)x;
		return (void *)(x + 1);
	}

}

__declspec(dllexport) void dp_free(void * mem)
{
	
	void*x = mem;

	int* add1 = (int *)x;
	int adjust = 4;
	int* add =add1- adjust;
	

	printf("%d", add[0]);

	freeList(*add1, add[0]);
}

__declspec(dllexport) void dp_debug()
{

}
