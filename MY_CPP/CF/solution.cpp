// #include<iostream>
// using namespace std;
// bool solve();
// #define ll long long int
// bool hasDistinct(ll x);
// ll sumOfDigits(ll x);
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         if(!solve())
//             cout<<"-1\n";
//     }
//     return 0;
// }
// ll revNum(ll num)
// {
//     ll rev = 0;
//     while(num)
//     {
//         rev = rev*10 + num%10;
//         num /= 10;
//     }
//     return rev;
// }
// bool solve()
// {
//     ll x;
//     cin>>x;
//     if(x<=9)
//     {
//         cout<<x<<"\n";
//         return true;
//     }
//     else if(x>45)
//     {
//         return false;
//     }
//     else
//     {
//         ll digit = 9;
//         ll res = 0;
//         while(x > 0)
//         {
//             if(digit <= x)
//             {
//                 res = res*10 + digit;
//                 x -= digit;
//                 digit--;
//             }
//             else
//             {
//                 res = res*10 + x;
//                 x = 0;
//             }
//         }
//         cout<<revNum(res)<<"\n";
//         return true;
//     }
// }


struct item  
{
    int data;
    int Min;
};

item stack[500];
int top = -1;

void push(int data)
{
    if(i == 499)    return;
    if(top == -1)
    {
        stack[i+1].data = data;
        stack[i+1].Min = data;
    }
    else
    {
        stack[i+1].data = data;
        stack[i+1].Min = min(data , stack[i].Min);
    }
    i++
}

void pop()
{
    if(top == -1)
        return;
    else
    {
        top-=1;
    }
}
int peekTop()
{
    if(top == -1)
    {
        return 1000000;
    }
    else
    {
        return stack[i].Min;
    }
}