#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdio.h>
#include"SimpleH.h"
int main()
{

	//getName();
	//getAge();

	int *a = (int *)dp_malloc(10 * sizeof(int));
	printf("%d\n", a);

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

	
	for (i = 0; i < 4; i++)
	{
		scanf("%f", &a1[i]);

	}
	for (i = 0; i < 4; i++)
	{
		printf("%f\n", a1[i]);
	}

	dp_free(a1);

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




return 0;
}