#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<string.h>

struct user
{
	short id;
	int a;
	char name[10];
	char state[10];
};

struct student
{
	int id;
	char name[32];
};

struct DataPage
{
	struct student data[3];
	char unused[20];
}**dp;


struct IndexPage
{
	int childPage[16];
	int key[15];
	char unused[4];
}**ip;
int indexpageindex = -1;

char* seperator(char** stringp, const char* delim)
{
	char* start = *stringp;
	char* p;

	p = (start != NULL) ? strpbrk(start, delim) : NULL;

	if (p == NULL)
	{
		*stringp = NULL;
	}
	else
	{
		*p = '\0';
		*stringp = p + 1;
	}

	return start;
}

void initializeDataPage()
{
	dp = (struct DataPage **)malloc(400 * sizeof(struct DataPage *));
}

void initializeIndexPage()
{
	ip = (struct IndexPage **)malloc(400 * sizeof(struct IndexPage *));
}

struct DataPage *createPage()
{
	struct DataPage *newNode = (struct DataPage *)malloc(sizeof(struct DataPage));
	return newNode;
}

struct IndexPage* createIndexPage()
{
	struct IndexPage *newNode = (struct IndexPage *)malloc(sizeof(struct IndexPage));
	return newNode;
}

void loadDataPagesToMemory(int n)
{


	FILE *fp = fopen("randomuserdata.csv", "r");

	char *line = (char *)malloc(1000 * sizeof(char));

	dp = (struct DataPage **)malloc(400 * sizeof(struct DataPage *));




	int i = 0;
	int j = 0;
	//dp[0] = (struct DataPage *)malloc(400 * sizeof(struct DataPage));
	dp[0] = createPage();
	fgets(line, 1000, fp);

	while (fgets(line, 1000, fp) != NULL)
	{
		if (j == n)
			break;
		char *line2 = (char *)malloc(1000 * sizeof(char));
		strcpy(line2, line);

		char *t1 = seperator(&line2, ",");
		char *t2 = seperator(&line2, ",");



		dp[j]->data[i].id = atoi(t1);
		strcpy(dp[j]->data[i].name, t2);
		i++;

		if (i == 3)
		{
			i = 0;
			j++;
			//dp[j] = (struct DataPage *)malloc(400 * sizeof(struct DataPage));
			dp[j] = createPage();
		}
	}
	fclose(fp);

}

void loadIndexPagesToMemory(int n)
{
	++indexpageindex;
	ip[indexpageindex] = (struct IndexPage *)malloc(sizeof(struct IndexPage));
	ip[indexpageindex] = createIndexPage();

	int i;
	int j = 0;
	for (i = 0; i < 16; i++)
	{
		ip[indexpageindex]->childPage[i] = j;
		j *= 3;
	}
	for (i = 0; i < 15; i++)
	{
		ip[indexpageindex]->key[i] = dp[i + 1]->data->id;
	}

}

void dataPagesToFile(int n)
{
	int i;
	FILE *fp2 = fopen("randonuserdataoutput.bin", "wb");

	for (i = 0; i < n; i++)
	{
		DataPage tempdp = *dp[i];
		fwrite(&tempdp, sizeof(struct DataPage), 1, fp2);
	}

	fclose(fp2);
}

void display(int n)
{
	int i, j;
	FILE *fp3 = fopen("randonuserdataoutput.bin", "rb");

	struct DataPage dd;
	for (i = 0; i < n; i++)
	{
		fread(&dd, sizeof(struct DataPage), 1, fp3);

		for (j = 0; j < 3; j++)
		{
			printf("%d  %s\n", dd.data[j].id, dd.data[j].name);
		}
	}
}

void displayFronIndexPage()
{
	struct IndexPage *tempip = ip[0];
	struct DataPage *tempdp = dp[0];
	FILE *fp = fopen("outputindex1.bin", "wb");


	printf("\n\n\n");
	int i, j;

	for (i = 0; i <= 15; i++)
	{
		tempip->childPage;

		printf("key : %d  value  : %s\n", dp[i]->data->id, dp[i]->data->name);
		DataPage tempdp = *dp[i];
		fwrite(&tempdp, sizeof(struct DataPage), 1, fp);

		tempip = ip[i];
	}


	FILE *fp3 = fopen("outputindex1.bin", "rb");

	struct DataPage dd;

	for (i = 0; i < 16; i++)
	{
		fread(&dd, sizeof(struct DataPage), 1, fp3);

		for (j = 0; j < 3; j++)
		{
			printf("%d  %s\n", dd.data[j].id, dd.data[j].name);
		}
	}


}

int main()
{
	printf("enter no of pages\n");
	int n;
	scanf("%d", &n);

	initializeDataPage();

	loadDataPagesToMemory(n);
	dataPagesToFile(n);
	display(n);



	initializeIndexPage();
	loadIndexPagesToMemory(n);
	displayFronIndexPage();


	return 0;
}