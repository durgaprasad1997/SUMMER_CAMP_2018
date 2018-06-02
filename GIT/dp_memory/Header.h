
#include<malloc.h>


int MAX_SIZE = 1024;
int current = -1;
void *myMemory;

int **baseAddress;
int baseAddIndex = 0;

struct FreeSize
{
	int address;
	int size;
	struct FreeSize *next;
};
struct FreeSize *head = NULL;
struct FreeSize *currentPos = head;



void sortedInsert(struct FreeSize** head_ref, struct FreeSize* new_node)
{
	struct FreeSize* current;

	if (*head_ref == NULL || (*head_ref)->address >= new_node->address)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{

		current = *head_ref;
		while (current->next != NULL &&
			current->next->address < new_node->address)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}


void insertionSort(struct FreeSize **head_ref)
{
	
	struct FreeSize *sorted = NULL;

	struct FreeSize *current = *head_ref;
	while (current != NULL)
	{
		struct FreeSize *next = current->next;


		sortedInsert(&sorted, current);

		
		current = next;
	}


	*head_ref = sorted;
}

void merger(struct FreeSize **head_ref)
{
	struct FreeSize *temp = *head_ref;
	while (temp->next!=NULL)
	{
		if (temp->address + temp->size == temp->next->address)
		{
			//under development


		}
			
	}
}

void freeToList(int memory, int size)
{
	
	if (head == NULL)
	{
		head = (struct FreeSize *)malloc(sizeof(struct FreeSize));

		head->next = NULL;
		currentPos = head;

		struct FreeSize *newnode = (struct FreeSize *)malloc(sizeof(struct FreeSize));
		newnode->next = NULL;
		newnode->address = memory;
		newnode->size = size;

		head = newnode;
		currentPos = newnode;
	}
	else
	{
		struct FreeSize *newnode = (struct FreeSize *)malloc(sizeof(struct FreeSize));
		newnode->next = NULL;
		newnode->address = memory;
		newnode->size = size;

		currentPos->next = newnode;
		currentPos = newnode;
	}

	insertionSort(&head);
	//merger(&head);

}

void deleteFreeSpace(struct FreeSize * t)
{
	struct FreeSize * headtemp = head;
	if (headtemp->address == t->address)
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
	baseAddress = (int **)malloc(15 * sizeof(int*));
	int i;
	for (i = 0; i < 15;i++)
		baseAddress[i] = (int *)malloc(sizeof(int));

	baseAddress[0]= (int *)myMemory;
}

void* dp_malloc(int size)
{

	if (current == -1)
	{
		init();
	}

	int temp;
	if ((temp = getFreeSpace(size)) != -1000)
	{

		int *x = (int *)temp;
		current = 0;
		x[current] = size;
		current += 1;
		x += current;

		current++;

		return (void *)(x);

	}
	else
	{
		if ((int *)myMemory+ size - baseAddress[baseAddIndex] >= 1024)
		{
			//printf("insufficient size\n");
			//return NULL;
			baseAddIndex++;
			void *extra = (int *)malloc(1024);

			baseAddress[baseAddIndex] = (int *)extra;
			myMemory = (int *)extra;
		}
		int *x = (int *)myMemory;
		current = 0;
		x[current] = size;
		//current += 4;
		current += 1;
		x += current;

		current++;
		myMemory = (void *)x;
		
		return (void *)(x);
	}

}

void dp_free(void * mem)
{
	int* add1 = (int *)mem;
	
	int add;
	add1 -= 1;
	add = add1[0];

	
	int x =(int) add1;

	freeToList(x, add);
}

//adding b/w slots
//sorted free list
