#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;
const int maxn=100005;
int a[maxn];
int C(int n, int k){
    if(n==1) return 1;
    if(k==0 || k==n) return 1;
    if(k==1 || k==n-1) return n;
    return C(n-1,k)+C(n-1, k-1);
}
int main()
{
    int n;
    ifstream cin("zoj.txt");
    while(cin>>n){
            //1.0 input
            for(int i=0; i<n; ++i) cin>>a[i];
            sort(a, a+n);

            //2. find dx min
            map<int, int> mp;
            for(int i=1; i<n; ++i) mp[a[i]-a[i-1]]++;
            map<int,int>::iterator it=mp.begin();
            if(mp.size()==1 && it->second==n-1) {
                cout<<1<<" "<<1<<endl;
                continue;
            }
            //cout<<it->second<<" ";

            //3. find dx max
            //统计最小值和最大值的个数x,y x*y为结果
            int tmin=1, tmax=1;
            for(int i=1; i<n; ++i){
                if(a[i]==a[0]) ++tmin;
                else break;
            }
            for(int i=n-2; i>=1; --i){
                if(a[i]==a[n-1]) ++tmax;
                else break;
            }
            cout<<it->second+(C(tmax,2)-tmax+1)+(C(tmin, 2)-tmin+1)<<" "<<tmin*tmax<<endl;
            //output
        	memset(a, 0, sizeof(a));
    }
    return 0;
}
