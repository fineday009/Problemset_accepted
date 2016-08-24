#include <iostream>
#include <cstdio>
#include <stack>
#include <deque>
using namespace std;

stack<int> st;

int main()
{
    int T, n, k , input;
    while(cin>>T){
        while(T--){
            cin>>n>>k;

            deque<int> a, b;//init 2 queue
            for(int i=1; i<=2*n; ++i){
                cin>>input;
                if(i<=n) { a.push_back(input);}
                else { b.push_back(input);}
            }

            while(k--){//shuffle
                while(!b.empty()){
                    st.push(b.back());
                    b.pop_back();
                    st.push(a.back());
                    a.pop_back();
                }
                //stack pop
                if(k==0) break;
                int cnt=0;
                while(!st.empty()){
                    cnt++;
                    int t=st.top();
                    st.pop();
                    if(cnt>n){ b.push_back(t);}else{ a.push_back(t);}
                }
            }

            int size=st.size();
            for(int i=0; i<size; ++i) { printf("%d%c", st.top(), i==size-1?'\n':' '); st.pop();}//print info
        }
    }

    return 0;
}
