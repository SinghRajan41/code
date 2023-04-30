#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
    // problem statement        https://www.youtube.com/watch?v=NkfIUo_Qq4c&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=24
    int pipe1[2],pipe2[2],pipe3[2];
    if(pipe(pipe1) == -1)   {return 1;}
    if(pipe(pipe2) == -1)   {return 2;}
    if(pipe(pipe3) == -1)   {return 3;}
    int id = fork();
    if(id != 0)
    {
        //parent process
        close(pipe1[0]);
        printf("Enter a number = ");    int x;  scanf("%d" , &x);
        if(write(pipe1[1] , &x , sizeof(int)) == -1){return 4;}
        //wait(NULL);
        close(pipe1[1]);
    }
    else
    {
        //child 1
        close(pipe1[1]);    close(pipe2[0]);    close(pipe3[0]);    close(pipe3[1]);
        int x;
        if(read(pipe1[0] , &x , sizeof(int)) == -1) {return 5;}//child 1 read from parent
        x+=6;
        if(write(pipe2[1] , &x , sizeof(int)) == -1)    {return 6;}
        close(pipe1[0]);    close(pipe2[1]);
        return 0;
    }
    id = fork();
    if(id == 0)
    {
        //child 2
        int x;
        if(read(pipe2[0] , &x , sizeof(int)) == -1) {return 7;}
        x+=9;
        if(write(pipe3[1] , &x , sizeof(int)) == -1) {return 8;}
        close(pipe2[0]);    close(pipe2[1]);
        close(pipe3[0]);    close(pipe3[1]);
    }
    else
    {
        //parent process
        int x;
        if(read(pipe3[0] , &x , sizeof(int)) == -1) {return 9;}
        printf("Value recieved after circulation = %d\n" , x);
        close(pipe2[0]);    close(pipe3[1]);    close(pipe3[0]);close(pipe2[1]);   
        wait(NULL); 
    }
    return 0;
}