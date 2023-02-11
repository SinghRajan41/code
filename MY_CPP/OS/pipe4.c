#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    //Enter username in child and send to parent process
    int fd[2];
    pipe(fd);
    int id = fork();
    if(id == 0)
    {
        char name[30];
        printf("Enter Your Name : ");
        fgets(name , 30 , stdin);
        close(fd[0]);
        int size = strlen(name);
        write(fd[1] , &size , sizeof(int));
        write(fd[1] , name , strlen(name));
        close(fd[0]);
    }
    else
    {
        wait(NULL);
        char name[30];
        close(fd[1]);
        int size;
        read(fd[0] , &size , sizeof(int));
        read(fd[0] , name ,size);
        printf("Hello : Welcome : %s\n" , name);
    }
    return 0;
}