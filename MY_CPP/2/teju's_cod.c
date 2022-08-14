#include<stdio.h>
int main()
{
   int dob;
   printf("Enter your DOB=");
   scanf("%d",&dob);
   int n=dob,bin=0;
   while(n)
   {
    bin=bin*10 + n%2;
    n=n/2;
   }
   printf("\n%d",bin);
}