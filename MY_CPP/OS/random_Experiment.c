#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    for(int i=0;i<15;i++)
        fork();
    printf("P ");
    return 0;
}