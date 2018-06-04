#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include"UserOptions.h"


int main()
{
	while (1)
	{
		printf("\nMENU\n");
		printf("1:login\n");
		printf("2:create user\n");
		
		printf("3:exit\n");

		int ch;
		printf("enter choice\n");
		scanf("%d", &ch);
		char *uname = (char *)malloc(100 * sizeof(char));
		char *password = (char *)malloc(100 * sizeof(char));
		struct User *user = (struct User *)malloc(sizeof(struct User));
		bool log;
		switch (ch)
		{
		case 1:
			printf("enter username ND password\n");
			
			scanf("%s", uname);
			scanf("%s", password);
			log=login(uname,password);
			if (log == true)
			{
				printf("successfully logged in");
				userOptions(uname);
			}
			else
			{
				printf("no such user\n");
			}
			break;
		case 2:
			printf("enter username\n");
			scanf("%s", user->userName);
			printf("enter password\n");
			scanf("%s", user->password);
			printf("enter email\n");
			scanf("%s", user->email);
			printf("enter phno\n");
			scanf("%s", user->phno);
			createUser(user);
			break;
		case 3:
			return 0;

		}
	}


	return 0;
}