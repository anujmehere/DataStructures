#include<iostream>
#include<vector>
using namespace std;

//1.Number of Digits
//iterative
int num_dig(int n)
{
    int count=0;
    while(n>0)
    {
        n=n/10;
        count++;
    }
    return count;
}
//recursive
int count_dig(int n)
{
    if(n==0)
        return 0;
    return 1+count_dig(n/10);
}
//logarithmic soln
int cnt_dig(int n)
{
    return 0; //return floor(log10(n))+1;
}

//2. Prime numbers
//every prime nos. can be represented as 6n+1 or 6n-1 except 2 or 3

//3. Palindrome Number
bool palindrome(int n)
{
    int test=n;
    if(n<=9) return true;
    int n2=0;
    while(n>0)
    {
        n2=(10*n2)+(n%10);
        n=n/10;
    }
    if(n2==test)
        return true;
    else 
        return false;
}

//4. Factorial of Number
int fact(int n)
{
    if(n==0 || n==1)
        return 1;
    return n*fact(n-1);
}

//5. Count trailing zeros in a factorial
int cnt_zero(int n)
{
    int count=0;
    for(int i=5;i<n;i*5)
    {
        count=count+(n/i);
    }
    return count;
}

//6. GCD of two numbers
int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

//7.LCM of two numbers
int lcm(int a, int b)
{
    int res=max(a,b);
    while(true)
    {
        if(res%a==0 && res%b==0)
        {
            return res;
        }
        res++;
    }
    return res;
}

int LCM(int a, int b)
{
    return (a*b)/gcd(a,b);
}

//8. Check Prime
bool is_Prime(int n)
{
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i=i+6)
    {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}

//9. Prime Factors
void prime_factors(int n)
{
    if(n<=1) return ;
    while(n%2==0)
    {
        cout<<2;
        n=n/2;
    }
    while(n%3==0)
    {
        cout<<3;
        n=n/3;
    }
    for(int i=5;i*i<=n;i=i+6)
    {
        while(n%i==0)
        {
            cout<<i;
            n=n%i;
        }
        while(n%(i+2)==0)
        {
            cout<<i+2;
            n=n%i+2;
        }
    }
    if(n>3) cout<<n;
}

//10. All Divisors of a Number
void printdivs(int n)
{
    int i = 1;
	for(i=1; i*i < n; i++)
	{
		if(n%i==0)
		{
			cout<<i<<" ";
		}
	}

	for(; i>=1;i--)
	{
		if(n%i==0)
		{
			cout<<(n/i)<<" ";
		}
	}
}

//11. Sieve of Eratosthenes
//all prime nos smaller than given number
void sieve(int n)
{
    vector<bool> isPrime(n+1,true);
    for(int i=2;i<=n;i++)
    {
        if(is_Prime(i))
        {
            cout<<i;
            for(int j=i*i;j<=n;j=j+i)
            {
                isPrime[j]=false;
            }
        }


    }

}

//12. computing power
int powerc(int x, int n)
{
	if(n == 0)
		return 1;
	int temp = powerc(x, n/2);
	temp = temp * temp;
	if(n % 2 == 0)
		return temp;
	else
		return temp * x; 
}

//13 . iterative power
int poweri(int x, int n)
{
    int res=1;
    while(n>0)
    {
        if(n&1)
            res=(res*x);
        x=(x*x); 
        n=n>>1; 
    }
    return res;
}
int main()
{
    cout<<fact(6);
}