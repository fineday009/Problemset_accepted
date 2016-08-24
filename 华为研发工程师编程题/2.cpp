#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, x;
    while(cin>>n){
        set<int> st;
        while(n--){ cin>>x; st.insert(x);}

        for(set<int>::iterator it=st.begin(); it!=st.end(); ++it) cout<<*it<<endl;
    }
    return 0;
}
