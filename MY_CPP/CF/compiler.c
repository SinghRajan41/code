#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define isAlpha(x) ((x>='A' && x<='Z') || (x>='a' && x<='b'))
void findWords(char str[] , char *words[]);
int main()
{
	char *str;	int idx = 0;
	FILE *fp = fopen("input.c" , "r");
	if(fp == NULL)
	{
		printf("Invalid File Name\n");
		exit(0);
	}
	int x = fgetc(fp),size = 0;
	while(x != -1)
	{
		size++;
		x = fgetc(fp);
	}
	fseek(fp , 0 , SEEK_SET);
	
	str = (char *)malloc(size);
	for(int i=0;i<=size;i++)
		str[i] = '\0';
	x = fgetc(fp);
	while( x!= -1)
	{
		str[idx++] = (char) x;
		x = fgetc(fp);
	}
	char *words[size / 2];
	for(int i=0;i<size/2;i++)	words[i] = NULL;
	//printf("%d\n" , size);
	//printf("%s" , str);
	findWords(str , words);
	return 0;
}
void findWords(char str[] , char *words[])
{
	int size = strlen(str);
	int r,l;
	printf("%d" , size);
	l = r = 0;
	char temp[100];
	int idx = 0;
	int k = 0;
	while(r < size)
	{
		if(isAlpha(str[r]))
		{
			temp[idx++] = str[r];	
		}
		else
		{
			if(isAlpha(temp[0]))
			{
				printf("a ");
				strcpy(words[k++] , temp);	
			}
			for(int i=0;i<100;i++)	temp[i] = '\0';
		}
		r++;
	}
	for(r=0 ; r<k ; r++)
	{
		printf("%s\n" , words[r]);
	}
}