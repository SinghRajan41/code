#include <iostream>
using namespace std;
bool isSmith(int num);
int sumOfDigits(int num);
bool isPrime(int num);
// A smith number is number that is composite and sum of digits of the number is equal to sum of the digits of its factors
// Write a code to check if a number is smith number or not
int main()
{
   int num;
   cin >> num;
   cout << (isSmith(num) ? "Smith Number\n" : "Not a smith Number");
   return 0;
}
int sumOfDigits(int num)
{
   int sum = 0;
   while (num > 0)
   {
      sum += (num % 10);
      num /= 10;
   }
   return sum;
}
bool isPrime(int num)
{
   if (num < 3)
   {
      return true;
   }
   for (int i = 2; i * i <= num; i++)
   {
      if (num % i == 0)
      {
         return false;
      }
   }
   return true;
}
bool isSmith(int num)
{
   if (isPrime(num))
   {
      return false;
   }
   else
   {
      if (num < 3)
      {
         return true;
      }
      else
      {
         int x = sumOfDigits(num);
         int temp = num;
         int i = 2;
         int y = 0;
         while (num > 1)
         {
            while (num % i == 0)
            {
               y += sumOfDigits(i);
               num /= i;
            }
            i++;
         }
         cout << x << " " << y << endl;
         return x == y;
      }
   }
}