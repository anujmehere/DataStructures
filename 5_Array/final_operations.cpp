#include<iostream>
using namespace std;
#include<vector>
 int finalValueAfterOperations(vector<string>& operations) 
 {
     int x=0;
     for(int i=0;i<operations.size();i++)
     {
         if(operations[i]=="X++" || operations[i]=="++X")
         {
             x++;
         }
         else if(operations[i]=="X--" || operations[i]=="--X")
         {
             x--;
         }

     }
     return x;
        
    
 }

int main()
{ 
    vector<string> num1 = {"++X","++X","X++"};
    cout<< finalValueAfterOperations(num1);
    return 0;
}