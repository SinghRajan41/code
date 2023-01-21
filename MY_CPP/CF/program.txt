#include<stdio.h>
#include<string.h>
int main()
{
    int a,b;
    char ch;
    printf("Enter two numbers = ");
    scanf("%d%d" , &a,&b);
    scanf("%c" , &ch);
    switch(ch)
    {
        case '+':
            printf("%d\n" , a+b);
            break;
        case '-':
            printf("%d\n" , a - b);

            break;
        case '*':
            printf("%d\n", a*b);

            break;
        case '/':
            printf("%d\n" , a/b);

            break;
        default:
            printf("Enter a valid Choice");

            break;
    }
    for(int i=0;i<10;i++)
    {
        printf("%d " , i);
    }
    return 0;
}