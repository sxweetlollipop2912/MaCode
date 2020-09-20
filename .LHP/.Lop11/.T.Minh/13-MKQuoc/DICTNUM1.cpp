#include <iostream>
#include <cstdio>

using namespace std;
int dp[10005][105];
int a[10005];
int n,m,k,t,cnt=0;
int bs(int n,int t)
{
    int l=0,r=n*k-1,mi;
    while(l+1<r)
    {
        mi=(l+r)/2;
        if(dp[mi][n]<t) r=mi-1;
        else l=mi;
    }
    if(l==r) return l;
    if(dp[r][n]<t) return l; else return r;
}
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("DICTNUM1.inp","r",stdin);
    freopen("DICTNUM1.out","w",stdout);
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
    for(int i=1;i<=28;i++)
    {
        t=i;
        int nn=n;
        t=dp[0][n]-t+1;
        while(nn!=0)
        {
            int tmp=bs(nn,t);
            for(int i=0;i<k-(tmp%k);i++) cout<<(tmp/k)+1<<" ";
            t-=dp[tmp+1][nn];
            nn-=a[tmp];
        }
        cout<<endl;
    }
    return 0;
}
