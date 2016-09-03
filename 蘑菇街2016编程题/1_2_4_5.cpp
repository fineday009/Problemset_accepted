//A 逻辑题
#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
int main()
{
    LL r, x, y, x1, y1;

    while(cin>>r>>x>>y>>x1>>y1){
        LL ans=0;
        LL dis=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
        if(dis%(2*r)==0) ans=dis/(2*r);
        else{
            while(dis>=r){
                ans++;
                dis-=2*r;
            }
            ans+=2;
        }

        cout<<ans<<endl;
    }

    return 0;
}

//B 暴力法
#include<iostream>
#include<cstdio>
using namespace std;
int a[105];
int main()
{
    int n;
    while(~scanf("%d", &n)){
        for(int i=1; i<=n; i++) scanf("%d", a+i);

        int res=INT_MAX;
        for(int i=2; i<=n-1; ++i){
            int per_ans=INT_MIN;
            bool meet=false;
            for(int j=2; j<=n; ++j){
                int x;
                if(i==j){//删除了i号
                    meet=true;
                }else{
                    if(meet) { x=a[j]-a[j-2]; meet=false;}
                    else x=a[j]-a[j-1];

                    if(x>per_ans) per_ans=x;
                }
            }

            if(per_ans<res) res=per_ans;
        }
        cout<<res<<endl;
    }
    return 0;
}


//C字符串模拟
#include<iostream>
using namespace std;

int main()
{
    string s;
    while(cin>>s){
        //bf n个位置
        bool success=false;
        for(int i=0, n=s.length(); i<=n; ++i){
            //插入到第i个位置 0<=i<=n
            //i---a[n-i]已经对应
            bool per_res=true;
            for(int j=0, k=n-1; j<k; ++j, --k){
                if(j==i || k==i){
                    //跳过该字符和其对应字符
                    if(j==i){
                      --k;
                      if(s[j]!=s[k]){
                        per_res=false;
                        break;
                      }
                    }
                    else{
                       ++j;
                       if(s[j]!=s[k]){
                        per_res=false;
                        break;
                      }
                    }
                }else if(s[j]!=s[k]){
                    per_res=false;
                    break;
                }
            }
            if(per_res==true){ success=true; break;}
        }

        if(success) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}


//D bool数组模拟
#include<iostream>
using namespace std;
const int maxn=300+5;
int a[maxn];

int main()
{
    int p, n, ans;
    while(cin>>p>>n){
        bool b[305], end=false, first=true;
        for(int i=0; i<p; ++i) b[i]=0;
        for(int i=0; i<n; ++i){
            int x;
            cin>>x;
            if(b[x%p] && first) { end=true; ans=i+1; first=false;}
            else b[x%p]=true;
        }
        cout<<(end?ans:-1)<<endl;
    }
    return 0;
}

