#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int flag_1,flag_2;
int main()
{
    //two way communication between parent and child
    int fd[2]; 
    flag_1 = flag_2 = 0; 
    if(pipe(fd) == -1)
    {
        printf("Pipe creation failed\n");
        return 1;
    }
    int id = fork();
    if(id != 0)
    {
        //parent process
        int arr[10];
        for(int i=0;i<10;i++)   arr[i] = rand() % 1000;
        printf("Array sent to child = ");   for(int i=0;i<10;i++)   printf("%d " , arr[i]);
        printf("\n");
        write(fd[1] , arr , 10 * sizeof(int));
        sleep(1);
        flag_1++;
        //while(flag_2 ==0)   ;        //wait for child to modify the array and send it to parent process
        read(fd[0] , arr , sizeof(int) * 10);
        printf("Array recieved from child = "); for(int i=0;i<10;i++)   printf("%d " , arr[i]); 
        close(fd[0]);   close(fd[1]);
        printf("\n");
    }
    else
    {
        //child process
        int n = 10;
        int arr[10];
        //wait for parent to create the array
        //while(flag_1 == 0)  ;
        read(fd[0] , arr , sizeof(int) * 10);
        for(int i=0;i<10;i++)   arr[i] = arr[i]<<1;
        write(fd[1] , arr , sizeof(int) * 10);
        flag_2++;
        close(fd[0]);   close(fd[1]);
    }
    if(id != 0)
    {
        wait(0);//wait for child process to finish
    }
    return 0;
}