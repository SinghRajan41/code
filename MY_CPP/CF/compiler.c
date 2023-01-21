#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define isAlpha(x) ((x>='A' && x<='Z') || (x>='a' && x<='z'))
void findWords(char str[] , char words[][100]);
void STRCPY(char *dest , char *src);
void findKeyWords(int size,char words[][100]);
void findSymbols(char str[] , int size);
void findIdentifiers(int size , char words[][100]);
#define prt(x)	printf("%c",x)
int main(int argc , char * argv[])
{
	char *str;	int idx = 0;
	FILE *fp = fopen(argv[1] , "r");
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
	size++;
	str = (char *)malloc(size);
	for(int i=0;i<=size;i++)
		str[i] = '\0';
	idx = 0;
	x = fgetc(fp);
	while(x != -1)
	{
		str[idx++] = x;
		x = fgetc(fp);
	}
	char words[size/2][100];
	char empty[] = "";
	for(int i=0;i<size/2;i++)
		STRCPY(words[i] , empty);
	findWords(str , words);
	findKeyWords(size/2,words);
	findSymbols(str , size);
	findIdentifiers(size>>1 , words);
	return 0;
}
void findIdentifiers(int size , char words[][100])
{
	printf("##############################   Identifiers listed below       #####################################\n");	
	char keys[][30] = {"auto",	"break",	"case",	"char",	"const",	"continue", 	"default",	"do",
						"double",	"else",	"enum",	"extern",	"float",	"for",	"goto", 	"if",
						"int",	"long",	"register",	"return",	"short",	"signed",	"sizeof",	"static",
						"struct",	"switch",	"typedef",	"union",	"unsigned"	,"void"	, "volatile"	,"while" , "main" , "stdio" , "string" , "stdlib" , "conio" , "ctype" , "math"};
	int n = 38;
	for(int i=0;i<size;i++)
	{
		int f = 1;
		for(int j=0;j<n;j++)
		{
			if(strcmp(keys[j] , words[i]) == 0)
			{
				f = 0; 
				break;
			}
		}
		int f2 = 1;
		for( int j=0 ; j<strlen(words[i]) ; j++)
		{
			if(!isAlpha(words[i][j]))
				f2 = 0;
		}
		if(f && isAlpha(words[i][0]) && f2)	printf("%s\n" , words[i]);
	}
	
}
void findSymbols(char str[] , int size)
{
	int keys[256];
	for(int i=0;i<256;i++)	keys[i] = 0;
	char sym[] = {'+' , '-' , '*' , '/' , '.' , '?' , '^' , ';' , ',' , '!' , '@' , '&' , '(' , ')' , '=' , '%' };
	int n = 16;
	for(int i=0;i<n;i++)	keys[(int)sym[i]] = 1;
	printf("##############################   Symbols listed below       #####################################\n");
	for(int i=0;i<size;i++)
	{
		if(keys[(int) str[i]])
			printf("%c  " , str[i]);
	}
	printf("\n\n\n");
}
void findKeyWords(int size,char words[][100])
{
	char keys[][30] = {"auto",	"break",	"case",	"char",	"const",	"continue", 	"default",	"do",
						"double",	"else",	"enum",	"extern",	"float",	"for",	"goto", 	"if",
						"int",	"long",	"register",	"return",	"short",	"signed",	"sizeof",	"static",
						"struct",	"switch",	"typedef",	"union",	"unsigned"	,"void"	, "volatile"	,"while", "main"};
	int n = 32;
	printf("##############################   Keywords listed below       #####################################\n");
	for(int i=0;i<size;i++)
	{
		int f = 0;
		for(int j=0;j<n;j++)
		{
			if(strcmp(keys[j] , words[i]) == 0)
			{
				f = 1;break;
			}
		}
		if(f){printf("%s   \n" , words[i]);}
	}
	printf("\n\n");
}
void findWords(char str[] , char words[][100])
{
	int size = strlen(str);
	char temp[100];
	int l,r;	l = r = 0;
	int k = 0;
	int idx = 0;
	while(r < size)
	{
		if(str[r] == '#')
		{
			while(r<size && str[r] != '>')	r++;
		}
		if(str[r] == '"')
		{
			while(r+1<size && str[r+1] != '"')
			{
				r++;
				idx = 0;
				temp[idx] = '\0';
			}
			r++;
		}
		if(isAlpha(str[r]))
		{
			temp[idx++] = str[r];
			temp[idx] = '\0';
		}
		else
		{
			idx = 0;
			short flag = 1;
			for(int i=0;i<k;i++)
			{
				if(strcmp(temp , words[i]) == 0)
				{
					flag = 0;break;
				}
			}
			if(flag && strlen(temp) > 0)
			{
				STRCPY(words[k++] , temp);
			}
		}
		r++;
	}
}
void STRCPY(char *dest , char *src)
{
	while(*src != '\0')
	{
		*dest = *src;
		dest++;	src++;
	}
}