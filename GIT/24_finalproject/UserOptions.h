#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include"UserCrud.h"


void userOptions(char *uname)
{

	printf("MENU\n");
	printf("1:remove user\n");
	printf("2:update user\n");
	printf("3:get user\n");
	printf("4:post\n");
	printf("5:comment\n");
	printf("6:like post\n");
	printf("7:remove post\n");
	printf("8:update post\n");
	printf("9:save post\n");
	printf("10:message user\n");
	printf("11:get all messages\n");
	printf("12:view Comments\n");
	printf("13:delete Comments\n");
	printf("14:logout");

	printf("enter choice\n");
	int ch;
	scanf("%d", &ch);


	struct User *user = (struct User *)malloc(sizeof(struct User));
	struct Post *post = (struct Post *)malloc(sizeof(struct Post));

	struct Message *message= (struct Message *)malloc(sizeof(struct Message));

	struct Comment *comment = (struct Comment *)malloc(sizeof(struct Comment));
	char *nameArray = (char *)malloc(100*sizeof(char));
	char *name2Array = (char *)malloc(100 * sizeof(char));

	switch (ch)
	{
		case 1 :
			removeUser(uname);
			break;
		case 2:
			strcpy(user->userName, uname);
			printf("enter new password\n");
			scanf("%s", user->password);
			printf("enter new email\n");
			scanf("%s", user->email);
			printf("enter new phno\n");
			scanf("%s", user->phno);
			updateUser(user);
			break;
		case 3:
			user = getUser(uname);
			printf("%s\n%s\n%s\n", user->userName, user->phno, user->email);
			break;
		case 4:
			fflush(stdin);
			strcpy(post->userName, uname);
			printf("enter postname\n");
			scanf("%s", post->postName);
			printf("enter postlink\n");
			scanf("%s", post->postName);
			post->likes = 0;
			addPost(post);
			break;
		case 5:
			strcpy(comment ->userName, uname);
			printf("enter postname name\n");
			scanf("%s", comment->postName);
			printf("enter commentorname\n");
			scanf("%s", comment->commentorName);
			printf("enter comment\n");
			scanf(" %[^\n]", comment->commentMsg);
			addComment(comment);
			break;
		case 6:
			printf("enter postName\n");
			scanf("%s", nameArray);
			likePost(nameArray);
			break;
		case 7:
			printf("enter username\n");
			scanf("%s", nameArray);
			printf("enter postname\n");
			scanf("%s", name2Array);
			removePost(nameArray, name2Array);
			break;
		case 8:
			printf("enter postname\n");
			scanf("%s", nameArray);
			printf("enter new message\n");
			scanf("%s", name2Array);
			updatePost(nameArray, name2Array);
			break;
		case 9:
			printf("enter postname\n");
			scanf("%s", name2Array);
			savePost(name2Array);
			break;
		case 10:
			strcpy(message->senderName, uname);
			printf("enter reciever username\n");
			scanf("%s", message->recieverName);
			printf("enter message\n");
			scanf("%s", message->message);
			addMessage(message);
			break;
		case 11:
			getAllMessages(uname);
			break;
		case 12:
			
			printf("enter postname\n");
			scanf("%s", nameArray);
			viewComment(nameArray);
			break;
		case 13:
			deleteComment(uname);
			break;
		case 14:
			printf("successfully logged out\n");
			return;
		

	default:
		break;
	}






}