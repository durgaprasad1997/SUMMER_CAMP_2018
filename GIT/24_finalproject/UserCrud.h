#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include"DBStructures.h"


struct User * getUser(char *name)
{

	FILE *fp = fopen("Database.bin", "rb");


	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData *));
	if (fread(metadata, sizeof(struct MetaData), 1, fp) <= 0)
	{
		return NULL;
	}

	while (feof(fp) != -1)
	{

		if (metadata->dataType == 1)
		{
			struct User*user = (struct User *)malloc(sizeof(struct User));
			if (fread(user, sizeof(struct User), 1, fp) <= 0)
				break;
			if (!strcmp(user->userName, name))
			{
				return  user;
			}

			


		}
		else if (metadata->dataType == 2)
		{
			fseek(fp, sizeof(struct Post), SEEK_CUR);
			


		}
		else if (metadata->dataType == 3)
		{
			fseek(fp, sizeof(struct Comment), SEEK_CUR);
			

		}
		else if (metadata->dataType == 4)
		{
			fseek(fp, sizeof(struct Message), SEEK_CUR);
			

		}
		else if (metadata->dataType == -1)
		{
			fseek(fp, sizeof(metadata->size), SEEK_CUR);
			
		}
		if (fread(metadata, sizeof(struct MetaData), 1, fp) <= 0)
		{
			return NULL;
		}
	
	}
	fflush(fp);
	fclose(fp);
	return NULL;

}

void createUser(struct User *user)
{

	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData *));
	metadata->dataType = 1;
	metadata->size = sizeof(user);
	FILE *fp = fopen("Database.bin", "ab+");
	
	if (getUser(user->userName) != NULL)
	{
		printf("already exist\n");
		return;
	}
	
	fwrite(metadata, sizeof(struct MetaData), 1, fp);
	fwrite(user, sizeof(struct User), 1, fp);
	fflush(fp);
	fclose(fp);

}


void updateUser(struct User *user2)
{

	FILE *fp = fopen("Database.bin", "rb+");

	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData *));

	while (fread(metadata, sizeof(struct MetaData), 1, fp)>0)
	{
		int current = ftell(fp);
		if (metadata->dataType == 1)
		{
			struct User*user = (struct User *)malloc(sizeof(struct User));
			if (fread(user, sizeof(struct User), 1, fp) == 0)
				break;
			if (!strcmp(user->userName, user2->userName))
			{
				fseek(fp, current,SEEK_SET);
				fwrite(user2, sizeof(struct User), 1, fp);
				fflush(fp);

				fclose(fp);
			
				return ;
			}
		}
		else if (metadata->dataType == 2)
		{
			fseek(fp, sizeof(struct Post) , SEEK_CUR);
			
		}
		else if (metadata->dataType == 3)
		{
			fseek(fp, sizeof(struct Comment) , SEEK_CUR);
		}
		else if (metadata->dataType == 4)
		{
			fseek(fp, sizeof(struct Message) , SEEK_CUR);
		
		}
		if (feof(fp) != -1)
		{
			fseek(fp, sizeof(struct MetaData) , SEEK_CUR);
			
		}

		
	}
	printf("no such user\n");
	fflush(fp);
	fclose(fp);
	return ;
}

void removeUser(char *name)
{

	FILE *fp = fopen("Database.bin", "rb+");
	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData *));
	int current = ftell(fp);
	while (fread(metadata, sizeof(struct MetaData), 1, fp) > 0)
	{
		
		if (metadata->dataType == 1)
		{
			struct User*user = (struct User *)malloc(sizeof(struct User));
			if (fread(user, sizeof(struct User), 1, fp) <= 0)
				break;
			if (!strcmp(user->userName, name))
			{
				fseek(fp, current, SEEK_SET);
				struct MetaData *newMetaData = (struct MetaData *)malloc(sizeof(struct MetaData));
				newMetaData->size = metadata->dataType;
				newMetaData->dataType = -1;

				fwrite(newMetaData, sizeof(struct MetaData), 1, fp);

				fflush(fp);

				fclose(fp);


				return;
			}

		}
		else if (metadata->dataType == 2)
		{
			struct Post*post = (struct Post *)malloc(sizeof(struct Post));
			if (fread(post, sizeof(struct Post), 1, fp) == 0)
				break;
			if (!strcmp(post->userName, name))
			{
				fseek(fp, current, SEEK_SET);
				struct MetaData *newMetaData = (struct MetaData *)malloc(sizeof(struct MetaData));
				newMetaData->size = metadata->dataType;
				newMetaData->dataType = -1;

				fwrite(newMetaData, sizeof(struct MetaData), 1, fp);

				fflush(fp);

				fclose(fp);


				return;
			}


			fseek(fp, sizeof(struct Post) , SEEK_CUR);

		}
		else if (metadata->dataType == 3)
		{

			struct Comment*comment = (struct Comment *)malloc(sizeof(struct Comment));
			if (fread(comment, sizeof(struct Comment), 1, fp) == 0)
				break;
			if (!strcmp(comment->userName, name))
			{
				fseek(fp, current, SEEK_SET);
				struct MetaData *newMetaData = (struct MetaData *)malloc(sizeof(struct MetaData));
				newMetaData->size = metadata->dataType;
				newMetaData->dataType = -1;

				fwrite(newMetaData, sizeof(struct MetaData), 1, fp);

				fflush(fp);

				fclose(fp);


				return;
			}

			fseek(fp, sizeof(struct Comment) , SEEK_CUR);


		}
		else if (metadata->dataType == 4)
		{
			fseek(fp, sizeof(struct Message), SEEK_CUR);

		}
		if (feof(fp) != -1)
		{
			fseek(fp, sizeof(struct MetaData) , SEEK_CUR);
			//fread(metadata, sizeof(struct MetaData), 1, fp);
		}

		current = ftell(fp);
	}
	printf("no such user\n");
	fflush(fp);
	fclose(fp);
	return;

}

bool login(char *name,char *password)
{

	FILE *fp = fopen("Database.bin", "rb");


	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData *));
	 
	 if (fread(metadata, sizeof(struct MetaData), 1, fp)<=0)
	{
		
		fclose(fp);
		return false;
	}

	while (feof(fp) != -1)
	{

		if (metadata->dataType == 1)
		{
			struct User*user = (struct User *)malloc(sizeof(struct User));
			if (fread(user, sizeof(struct User), 1, fp) <= 0)
				break;
			if (!strcmp(user->userName, name)&&!strcmp(user->password,password))
			{
				fclose(fp);
				return true;
			}

		

		}
		else if (metadata->dataType == 2)
		{
			fseek(fp, sizeof(struct Post) , SEEK_CUR);
			



		}
		else if (metadata->dataType == 3)
		{
			fseek(fp, sizeof(struct Comment) , SEEK_CUR);
			


		}
		else if (metadata->dataType == 4)
		{
			fseek(fp, sizeof(struct Message) , SEEK_CUR);
			


		}
		else if (metadata->dataType == -1)
		{
			fseek(fp, sizeof(metadata->size) , SEEK_CUR);
		
		}

		if (fread(metadata, sizeof(struct MetaData), 1, fp) <= 0)
		{

			fclose(fp);
			return false;
		}
	}
	fflush(fp);
	
	fclose(fp);
	return false;
}

void addPost(struct Post *post)
{
	FILE *fp = fopen("Database.bin", "ab+");

	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData));
	metadata->dataType = 2;
	metadata->size = sizeof(struct Post);
	fwrite(metadata, sizeof(struct MetaData), 1, fp);
	fwrite(post, sizeof(struct Post), 1, fp);
	fflush(fp);
	fclose(fp);

}


void addComment(struct Comment *comment)
{
	FILE *fp = fopen("Database.bin", "ab+");

	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData));
	metadata->dataType = 3;
	metadata->size = sizeof(struct Comment);
	fwrite(metadata, sizeof(struct MetaData), 1, fp);
	fwrite(comment, sizeof(struct Comment), 1, fp);
	fflush(fp);
	fclose(fp);
}

void addMessage(struct Message *message)
{
	FILE *fp = fopen("Database.bin", "ab+");

	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData));
	metadata->dataType = 4;
	metadata->size = sizeof(struct Message);
	fwrite(metadata, sizeof(struct MetaData), 1, fp);
	fwrite(message, sizeof(struct Message), 1, fp);
	fflush(fp);
	fclose(fp);
}


void likePost(char  *postname)
{


	FILE *fp = fopen("Database.bin", "rb+");

	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData *));

	while (fread(metadata, sizeof(struct MetaData), 1, fp) != 0)
	{
 
	
		int current = ftell(fp);
		if (metadata->dataType == 1)
		{
			fseek(fp, sizeof(struct User) , SEEK_CUR);
		}
		else if (metadata->dataType == 2)
		{
			int current = ftell(fp);
			struct Post *post = (struct Post*)malloc(sizeof(struct Post));

			fread(post, sizeof(struct Post), 1, fp);

			if (!strcmp(post->postName, postname))
			{
				post->likes++;
				fseek(fp, current, SEEK_SET);
				fwrite(post, sizeof(struct Post), 1, fp);
				fflush(fp);
			}


		}
		else if (metadata->dataType == 3)
		{
			fseek(fp, sizeof(struct Comment) , SEEK_CUR);
		}
		else if (metadata->dataType == 4)
		{
			fseek(fp, sizeof(struct Message) , SEEK_CUR);

		}
		if (feof(fp) != -1)
		{
			fseek(fp, sizeof(struct MetaData) , SEEK_CUR);
			
		}


	}
	fflush(fp);
	fclose(fp);
	printf("no such post\n");
	return;
}

void removePost(char *username, char *postname)
{

	FILE *fp = fopen("Database.bin", "rb+");

	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData *));
	int current = ftell(fp);
	while (fread(metadata, sizeof(struct MetaData), 1, fp) != 0)
	{
		if (metadata->dataType == 1)
		{
			fseek(fp, sizeof(struct User) , SEEK_CUR);
		}
		else if (metadata->dataType == 2)
		{
			int current = ftell(fp);
			struct MetaData*metadata = (struct MetaData*)malloc(sizeof(struct MetaData));
			struct Post *post = (struct Post *)malloc(sizeof(struct Post));

			fread(post, sizeof(struct Post), 1, fp);

			if (!strcmp(post->postName, postname)&&!strcmp(post->userName,username))
			{
				metadata->dataType = -1;
				fseek(fp, current, SEEK_SET);
				fwrite(metadata, sizeof(struct MetaData), 1, fp);
				fflush(fp);
			}


		}
		else if (metadata->dataType == 3)
		{
			fseek(fp, sizeof(struct Comment) , SEEK_CUR);
		}
		else if (metadata->dataType == 4)
		{
			fseek(fp, sizeof(struct Message) , SEEK_CUR);

		}
		if (feof(fp) != -1)
		{
			fseek(fp, sizeof(struct MetaData) + 1, SEEK_CUR);
		}

		current = ftell(fp);
	}
	printf("no such post\n");
	fflush(fp);
	fclose(fp);
	return;
}

void updatePost(char  *postname,char *newMessage)
{


	FILE *fp = fopen("Database.bin", "rb+");

	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData *));

	while (fread(metadata, sizeof(struct MetaData), 1, fp) != 0)
	{


		int current = ftell(fp);
		if (metadata->dataType == 1)
		{
			fseek(fp, sizeof(struct User) , SEEK_CUR);
		}
		else if (metadata->dataType == 2)
		{
			int current = ftell(fp);
			struct Post *post = (struct Post*)malloc(sizeof(struct Post));

			fread(post, sizeof(struct Post), 1, fp);

			if (!strcmp(post->postName, postname))
			{
				strcpy(post->post, postname);
				fseek(fp, current, SEEK_SET);
				fwrite(post, sizeof(struct Post), 1, fp);
				fflush(fp);
			}


		}
		else if (metadata->dataType == 3)
		{
			fseek(fp, sizeof(struct Comment) , SEEK_CUR);
		}
		else if (metadata->dataType == 4)
		{
			fseek(fp, sizeof(struct Message) , SEEK_CUR);

		}
		if (feof(fp) != -1)
		{
			fseek(fp, sizeof(struct MetaData), SEEK_CUR);

		}


	}
	fflush(fp);
	fclose(fp);
	printf("no such post\n");
	return;
}

void message(struct Message *message)
{
	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData *));
	metadata->dataType = 1;
	metadata->size = sizeof(message);
	FILE *fp = fopen("Database.bin", "wb");
	fwrite(metadata, sizeof(struct MetaData), 1, fp);
	fwrite(message, sizeof(struct Message), 1, fp);
	fclose(fp);
}

void getAllMessages(char *name)
{
	FILE *fp = fopen("Database.bin", "rb");


	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData *));
	if (fread(metadata, sizeof(struct MetaData), 1, fp) == 0)
	{
		return;
	}

	while (feof(fp) != -1)
	{

		if (metadata->dataType == 1)
		{
			
			fseek(fp, sizeof(struct User) , SEEK_CUR);
			

		}
		else if (metadata->dataType == 2)
		{
			fseek(fp, sizeof(struct Post) , SEEK_CUR);
		
		}
		else if (metadata->dataType == 3)
		{
			fseek(fp, sizeof(struct Comment) , SEEK_CUR);
			
		}
		else if (metadata->dataType == 4)
		{
			
			struct Message *message = (struct Message*)malloc(sizeof(struct Message));
			fread(message, sizeof(struct Message), 1, fp);
			if (!strcmp(message->recieverName, name))
				printf("sender-----%s\nmessage----%s\n", message->senderName, message->message);

		
		}
		else if (metadata->dataType == -1)
		{
			fseek(fp, sizeof(metadata->size) , SEEK_CUR);
			
		}
		if (fread(metadata, sizeof(struct MetaData), 1, fp) <= 0)
			break;
	}
	printf("no such username\n");
	return;

}

void viewComment(char *postname)
{

	FILE *fp = fopen("Database.bin", "rb");


	struct MetaData *metadata = (struct MetaData *)malloc(sizeof(struct MetaData *));
	if (fread(metadata, sizeof(struct MetaData), 1, fp) <= 0)
	{
		return ;
	}

	while (feof(fp) != -1)
	{

		if (metadata->dataType == 1)
		{
			
			fseek(fp, sizeof(struct User) , SEEK_CUR);
			

		}
		else if (metadata->dataType == 2)
		{
			fseek(fp, sizeof(struct Post) , SEEK_CUR);
			


		}
		else if (metadata->dataType == 3)
		{
			struct Comment *comment = (struct Comment*)malloc(sizeof(struct Comment));
			fread(comment, sizeof(struct Comment), 1, fp);
			if (!strcmp(comment->postName, postname))
			{
				printf("%s  %s\n", comment->commentorName, comment->commentMsg);
				return;
			}
		


		}
		else if (metadata->dataType == 4)
		{
			fseek(fp, sizeof(struct Message) , SEEK_CUR);
		
		}
		else if (metadata->dataType == -1)
		{
			fseek(fp, sizeof(metadata->size) , SEEK_CUR);
		
		}
		if (fread(metadata, sizeof(struct MetaData), 1, fp) <= 0)
			break;
	}
	printf("no such user\n");
	return;
}

void deleteComment(char *name)
{

}

void savePost(char *postname)
{

}