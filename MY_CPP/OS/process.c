#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int wait();
int main(int argc , char * arg[])
{
    //Create a child process to print half the array by main process and half the array by child process
    int arr[] = {1,2,3,4,5,n6,7,8,9,10};
    int id = fork();
    int n;
    if(id != 0)
    {
         n = 0;
    }
    else
    {
        n = 5;
    }
    if(id != 0)
    {
        wait();
    }
    for(int i=n;i<n+5;i++)
    {
        printf("%d " , arr[i]); //fflush(stdout);
    }
    printf("\n");
    
    return 0;
}