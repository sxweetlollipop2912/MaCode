#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <cmath>
#define inf 999999999
#define maxn 505
#define ll long long
using namespace std;
int n,len;
ll a[maxn];
ll f[maxn][maxn];
void nhap()
{
    cin>>len>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
}
void xuly()
{
    a[n+1]=len;
//    for (int i=0;i<=n;i++)
//        f[i][i+1]=a[i+1]-a[i];
    for (int l=2;l<=n+1;l++)
        for (int i=0;i+l<=n+1;i++){
            int j=i+l;
            f[i][j]=inf;
            for (int k=i+1;k<j;k++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            f[i][j]+=a[j]-a[i];
        }
    cout<<f[0][n+1];
}
int main()
{
    freopen("XAU.INP","r",stdin);
    freopen("XAU.OUT","w",stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    nhap();
    xuly();
    return 0;
}
