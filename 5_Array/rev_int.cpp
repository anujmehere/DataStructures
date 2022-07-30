#include<iostream>
using namespace std;

int main()
{
    int x;
    cin>>x;
    int rev = 0;
       while (x){
           int digit = x % 10;
           x /= 10;
           if ((rev > 0 && rev > (INT_MAX - digit)/10) | (rev < 0 && rev < (INT_MIN - digit)/10)) return 0;
           rev = rev * 10 + digit;
       }
    cout<<rev;
}