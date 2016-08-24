#include <iostream>
#include <stack>
using namespace std;

//void rev(stack<int>& s){
//    if(s.size()==1||s.size()==0) return;
//    int top=s.top(); s.pop();
//    rev(s);
//
//    int bottom=s.top(); s.pop();
//    rev(s); s.push(top);
//    rev(s); s.push(bottom);
//}

stack<int> rev(stack<int>& s){
    stack<int> t;
    while(!s.empty()){
        t.push(s.top());
        s.pop();
    }
    return t;
}

int main()
{
    stack<int> s;
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    stack<int> ss=s;
    while(!ss.empty()){
        cout<<ss.top()<<endl;
        ss.pop();
    }

    stack<int> t=rev(s);
    while(!t.empty()){
        cout<<t.top()<<endl;
        t.pop();
    }
    return 0;
}
