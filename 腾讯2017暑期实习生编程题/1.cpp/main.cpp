#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int maxn=1005;
int dp[maxn][maxn];

int LCS(string s, string t){
    int m=s.length(), n=t.length(), res=0;
    for(int i=0; i<=m; ++i){
        for(int j=0; j<=n; ++j){
            if(i==0 || j==0) dp[i][j]=0;
            else{
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
            if(dp[i][j]>res) res=dp[i][j];
        }
    }
    //cout<<"最长公共字串"<<res<<endl;
    return res;
}

int main(){
    //lcs问题
    //ifstream cin("zoj.txt");
    string s;
    while(cin>>s){
        string t;
//        reverse(s.begin(), s.end());
        t.assign(s.rbegin(), s.rend());
        int res=LCS(s,t);
        cout<<s.length()-res<<endl;
    }
    return 0;
}
