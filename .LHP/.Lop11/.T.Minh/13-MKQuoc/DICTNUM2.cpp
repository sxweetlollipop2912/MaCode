#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>

using namespace std;
int dp[10005][105];
int a[10005];
int n,m,k,t,cnt=0;
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("DICTNUM2.inp","r",stdin);
    freopen("DICTNUM2.out","w",stdout);
    cin>>n>>k;
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=k;j++)
//            for(int l=i-1;l>=1;l--)
//                for(int o=0;o<=j;o++) if(i<l*o) break;
//                    else dp[i][j][l]+=dp[i-j*o][j][l+1]
    for(int i=1;i<n;i++)
        for(int j=k;j>=1;j--)
        {
            dp[cnt][0]=1;
            a[cnt++]=i*j;
        }
    for(int i=1;i<=k;i++)
        for(int j=1;j<=i;j++)
            dp[cnt-i][(n-1)*j]=1;
    for(int i=cnt-k-1;i>=0;i--)
    {
        for(int j=1;j<=n;j++)
            if(j<a[i]) dp[i][j]+=dp[i+1][j];
            else dp[i][j]+=dp[i+k-(i%k)][j-a[i]]+dp[i+1][j];
    }
    cout<<dp[0][n]<<endl;
    //for(int i=0;i<cnt;i++) cout<<dp[i][n]<<" ";
    string s;
    getline(cin,s);
    while(getline(cin,s))
    {
        stringstream ss;
        vector<int> ve,v;
        int nn=n;
        ss<<s;
        while(ss>>t) ve.push_back(t);
        int cnt=1,num=ve[0];
        for(int i=1;i<ve.size();i++)
        {
            if(ve[i]!=ve[i-1])
            {
                v.push_back((num-1)*k+k-cnt);
                num=ve[i];
                cnt=1;
            }
            else ++cnt;
        }
        v.push_back((num-1)*k+k-cnt);
        int ans=0;
        for(int i=0;i<(int)v.size()-1;i++)
        {
            int tmp=dp[v[i]+1][nn];
            ans+=tmp;
            nn-=a[v[i]];
        }
        ans+=dp[v[(int)v.size()-1]][nn];
        cout<<(dp[0][n]-ans+1)<<endl;
    }
    return 0;
}
//6 4 2 2 1 0 0 0 0 0