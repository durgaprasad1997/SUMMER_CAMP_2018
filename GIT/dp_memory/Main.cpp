#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdio.h>
#include"Header.h"
int main()
{

	
	
	//getName();
	//getAge();

	int *a = (int *)dp_malloc(10 * sizeof(int));
	printf("%d\n", a);
	printf("enter 5 ints\n");
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		scanf("%d", &a[i]);

	}
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", a[i]);
	}


	float *a1 = (float *)dp_malloc(10 * sizeof(float));
	printf("%d\n", a1);

	printf("enter 5 ints\n");
	for (i = 0; i < 4; i++)
	{
		scanf("%f", &a1[i]);

	}
	for (i = 0; i < 4; i++)
	{
		printf("%f\n", a1[i]);
	}


	dp_free((void *)a);
	printf("enter 5 ints\n");
	int *a3 = (int *)dp_malloc(5 * sizeof(int));
	printf("%d\n", a3);

	i = 0;
	for (i = 0; i < 4; i++)
	{
		scanf("%d", &a3[i]);

	}
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", a3[i]);
	}

	char *a5 = (char *)dp_malloc(5 * sizeof(char));
	printf("%d\n", a5);
	printf("enter 5 ints\n");
	i = 0;
	for (i = 0; i < 4; i++)
	{
		fflush(stdin);
		scanf("%c", &a5[i]);

	}
	for (i = 0; i < 4; i++)
	{
		printf("%c\n", a5[i]);
	}



	int *a10 = (int *)dp_malloc(1000 * sizeof(int));
	printf("%d", a10);
 i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a10[i]);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", a10[i]);
	}

	dp_free(a10);
	printf("enter 5 ints\n");
	int *a11 = (int *)dp_malloc(100* sizeof(int));
	printf("%d", a11);
	 i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a11[i]);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", a11[i]);
	}
	

	
	return 0;
}