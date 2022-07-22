#include<iostream>
using namespace std;

//Bitwise Operator  -- operate on individual bits 
// &And |Or ^ex-or
//Consider x=3, y=6
//x=0011 y=0110 binary representation
//x&y = 2  /x&y=>0010 both should be 1 then o/p is 1
//x|y = 7  /x|y=>0111  at least one is 1 then o/p is 1
//x^y = 5  /x^y=>0101  both different bits then o/p is 1

//2. Left Shift Operator
//x<<1  lets x=3 binary form->0011
//o/p x<<1 -> 0110 = 6
//if we assume leading y bits are 0 then result of(x<<y) = x*(2^y)

//Right Shift Operator
//x>>1 lets x=9 binary form->1001
//o/p x>>1 -> 0100 = 4
//here if the last bit is 1/0 regardless of that 0 is added at the beginning of bits to maintain the num. of bits
//here x>>y is same as [x/(2^y)]

//Bitwise Not ~
//eg 32 bit reprs if x=1 -> 00....01  o/p ~x -> 11....10

//Signed nos
//if nos are stored in 32 bits then for signed will have 31 bits for nos and 1 bit for sign
//we use 2's complement method to counter two represenation of 0
//2's complent of x in n bits repr = (2^n) -x

//6.Check if kth bit is set
//n=5 k=3
//n-        >00....0101  k=3
//1        ->00....0001
//1<<(k-1) ->00....0100  if we do (n&(1<<k-1)) returns true
bool kthbit(int n,int k)
{
    if(n&(1<<(k-1)))
        return true;
    else
        return false;
}
//7. Count Set Bits
//Brian Kerningam Algortihm
int countbits(int n)
{
    int res=0;
    while(n>0)
    {
        n=(n&(n-1));
        res++;
    }
    return res;
}

//Power of two
//Check if given number is a power of 2
bool ispow(int n)
{
    if(n==0)
        return false;
    return (n&(n-1)==0);
}

//Find the only odd occuring number
//{4,3,4,4,4,5,5,3,3} --> here 3 occurs odd no of times i.e three times
int findodd(int arr[],int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        res=res^arr[i];
    }
    return res;
}

//find the two odd occuring elements
void oddAppearing(int arr[], int n)
{
        int xors = 0, res1 = 0, res2 = 0; 
        for (int i = 0; i < n; i++) 
        xors = xors ^ arr[i]; 
        int sn = xors & (~(xors - 1)); 
        for (int i = 0; i < n; i++) 
        { 
            if ((arr[i] & sn) != 0) 
                res1 = res1 ^ arr[i]; 
            else
                res2 = res2 ^ arr[i]; 
        } 
        cout<<res1<<" "<<res2;
}

//Print power set of a string
//abc ={"","a","b","c","ab","ac","bc","abc"}
void printPowerSet(string str)
{
	int n = str.length();
	int powSize = pow(2, n);
	for(int counter = 0; counter < powSize; counter++)
	{
		for(int j = 0; j < n; j++)
		{
			if((counter & (1 << j)) != 0)
                cout<<str[j];
		}
		cout<<endl;
	}
}
int main()
{
    
}