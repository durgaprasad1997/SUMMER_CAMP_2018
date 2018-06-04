#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#include<time.h>

//datatye 
//1-user
//2-post
//3-comment
//4-message
struct MetaData
{
	short dataType;
	short size;
};
struct User
{
	
	char userName[32];
	char password[16];
	char email[32];
	char phno[14];
};
struct Post
{

	char userName[32];
	char postName[20];
	char post[100];
	short postType;
	short postSize;
	short likes;

};
struct Comment
{
	char userName[32];
	char postName[20];
	char commentorName[32];
	char commentMsg[156];
};
struct Message
{
	char senderName[20];
	char recieverName[20];
	char message[50];
};