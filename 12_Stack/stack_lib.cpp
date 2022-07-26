#include<iostream>
#include<stack>
using namespace std;
//Stack in STL LIBrary
//As Stack is implemented using other containers and used as interface its called as container adapter.
//Stack,Queue and Priority Queue all are container adapters 
//it is implemented using list,vector,deque by default its implemented using deque
//for all operations it haas time complexity O(1)
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
}