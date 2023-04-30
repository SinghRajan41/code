#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    //create an array of random integers and pass it to 
    //child, the child multiplies each array element by 2 and returns it to parent, implement it using pipes
    int pipe1[2],pipe2[2];
    if(pipe(pipe1) == -1)
    {
        printf("Pipe 1 creation failed\n"); return 1;
    }
    if(pipe(pipe2) == -1)
    {
        printf("Pipe 2 Creation Failed\n");
    }
    int id = fork();
    if(id != 0)
    {
        //parent process
        close(pipe1[0]);
        close(pipe2[1]);
        int n = 10;
        int arr[n]; 
        srand(time(NULL));  
        for(int i=0;i<n;i++)    arr[i] = rand() % 15;
        printf("Array sent to child = ");
        for(int i=0;i<n;i++)    printf("%d ", arr[i]);
        printf("\n");
        write(pipe1[1] , &n , sizeof(int));
        write(pipe1[1] , arr , n * sizeof(int));
        wait(NULL);
        read(pipe2[0] , arr , sizeof(int) * n);
        printf("Array recieved from child = "); 
        for(int i=0;i<n;i++)    printf("%d " , arr[i]);
        printf("\n");    
    }
    else
    {
        close(pipe1[1]);    close(pipe2[0]);
        int n;
        read(pipe1[0] , &n , sizeof(int));
        int arr[n];
        read(pipe1[0] , arr , n * sizeof(int));
        for(int i=0;i<n;i++)    arr[i] <<= 1;
        write(pipe2[1] , arr , sizeof(int) * n);
        close(pipe1[0]);    close(pipe2[1]);
    }
}