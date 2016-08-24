#include <iostream>
using namespace std;

int help(int n)
{
    if(n==3 || n==2) return 1;
    if(n<=1) return 0;
    int res=0;
    res+=n/3+help(n/3+n%3);
    return res;
}

int main()
{
    int n;
    while(cin>>n){
        if(n==0) return 0;
        cout<<help(n)<<endl;
    }
    return 0;
}
