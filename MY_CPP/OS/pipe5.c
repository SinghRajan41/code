//Create three processes to distribute the work
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    int fd1[2];
    pipe(fd1);
    int id1 = fork();
    if(id1 == 0)
    {

    }
    else
    {
        int sum = 0;
    }
    return 0;
}