#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
    //WAP to read in paretn and child and exhange the values
    int fd[2];  pipe(fd);
    int id = fork();
    if(id != 0)
    {
        wait(NULL);
        //Parent process
        printf("Enter a vlaue for parent process : ");
        int x;  scanf("%d" , &x);
        if(write(fd[1] , &x , sizeof(int)) == -1)
        {
            printf("Error Writing in parent process\n");
                return 2;
        }
        if(read(fd[0] , &x , sizeof(int)) == -1)
        {
            printf("Error during read from parent process");
            return 3;
        }
        printf("Value Recieved from child Process = %d\n" , x);

        close(fd[0]);   close(fd[1]);
    }
    else
    {
        int x;
        printf("Enter a value for child process : ");
        scanf("%d" , &x);
        if(write(fd[1] , &x , sizeof(int)) == -1)
        {
            printf("Error during writing in child process\n");
            return 4;
        }
        if(read(fd[0] , &x , sizeof(int)) == -1)
        {
            printf("Error during reading in child process\n");
            return 5;
        }
        printf("Value recieved from parent = %d\n" , x);
        close(fd[0]);   close(fd[1]);
    }
    return 0;
}