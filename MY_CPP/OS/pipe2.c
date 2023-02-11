#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    //Write a program to read an integer in parent process and pass it to child process
    int fd[2];
    pipe(fd);
    int id = fork();
    if(id != 0)
    {
        //Parent Process
        int x;
        printf("Enter an Intger : ");   scanf("%d" , &x);
        if(write(fd[1]  , &x , sizeof(int)) == -1)
        {
            printf("Error During Wrinting to pipie\n");
            return 3;
        }
        close(fd[1]);   close(fd[0]);
    }
    else
    {
        //Child Process reads from the pipe and prints
        int x;
        if(read(fd[0] , &x , sizeof(int)) == -1)
        {
            printf("Error During Reading from Pipe\n");
            return 2;
        }
        printf("Value inherited from parent : %d\n" , x);
        close(fd[0]);close(fd[1]);
    }
    return 0;
}