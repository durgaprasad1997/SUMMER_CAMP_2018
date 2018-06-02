/*
// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
	struct sockaddr_in address;
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char *hello = "Hello from client";
	char buffer[1024] = { 0 };
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	send(sock, hello, strlen(hello), 0);
	printf("Hello message sent\n");
	valread = read(sock, buffer, 1024);
	printf("%s\n", buffer);
	return 0;
}
*/


#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<string.h>

int main()
{
	char *input = (char *)malloc(100 * sizeof(char));

	FILE *fp = fopen("C:/summer_system/i1.bin", "wb");

	while (1)
	{

		printf("1:string 2 : intnumber");
		int ch;
		scanf("%d", &ch);
		int status=1;
		char *c = (char *)malloc(100 * sizeof(char));
		int d;
		switch (ch)
		{
		case 1:
			scanf(" %[^\n]", c);
			status = strlen(c);
			fwrite(&status, 4, 0, fp);
			fflush(fp);
			fwrite(c, 40, 1, fp);
			fflush(fp);
			break;
		case 2:
			scanf("%d", d);
			status = -1;
			fwrite(&status, 4, 0, fp);
			fflush(fp);
			fwrite(c, 4, 1, fp);
			fflush(fp);
			break;
		}



	}


	
	

	
	return 0;
}