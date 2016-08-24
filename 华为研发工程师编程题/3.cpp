#include <iostream>
#include <map>
using namespace std;
typedef long long LL;

map<char, int> mp;
void init()
{
    int left='0', right=0;
    for(int i=0; i<=9; i++) mp[left+i]=right+i;

    left='A', right=10;
    for(int i=0; i<=5; i++) mp[left+i]=right+i;
}

int main()
{
    init();
    string x;
    while(cin>>x){
        LL res=0;
        for(int i=0, len=x.length(); i<len; ++i){
            res=(16*res+mp[x[i]]);
        }
        cout<<res<<endl;
    }
    return 0;
}
