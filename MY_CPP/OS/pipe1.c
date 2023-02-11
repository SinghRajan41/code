#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
    //Create a child process to read an integer and pass it to parent process
    int fd[2];
    if(pipe(fd) == -1)
    {
        printf("Error Ocurred With Pipe Creation\n");
        return 1;
    }
    int id = fork();
    if(id == 0)
    {
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100000;j++)
            {
                printf(".");
            }
        }
        int x; 
        printf("Enter an integer : ");  
        scanf("%d" , &x);
        if(write(fd[1] , &x , sizeof(int))== -1)
        {
            printf("Error while wrting to pipe\n"); 
                return 3;
        }
        close(fd[0]);   close(fd[1]);
    }
    else
    {
       //wait(NULL);
        int y;
        if(read(fd[0] , &y , sizeof(int)) == -1)
        {
            printf("Error While Reading from Pipe\n");
            return 2;
        }
        printf("Value got from child : %d\n\n" , y);
        close(fd[1]);   close(fd[0]);
    }
    return 0;
}