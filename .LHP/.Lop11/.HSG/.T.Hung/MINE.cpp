#include <bits/stdc++.h>
#define ll long long
#define NN 200005
#define R 1000003
#define inf 99999999
using namespace std;
ll catalan[NN],f[4005][2005];
int n,m;
vector<int>a;
ll mul(ll x, ll y){
    if (y==1)return x;
    ll re=mul(x,y/2);
    re=(re*re)%R;
    if (y%2==1)return (re*x)%R;
    return re;
}
void solve1(){
    ll ans=1LL;
    for (int i=n+2;i<=2*n;i++)
        ans=(ans*i)%R;
    ll tmp=1LL;
    for (int i=1;i<=n;i++)
        tmp=(tmp*i)%R;
    tmp=mul(tmp,R-2);
    ans=(ans*tmp)%R;
    cout<<ans;
}
void Prepare(){
    catalan[0]=1;
    for (int i=1;i<=n;i++){
        catalan[i]=0;
        for (int j=0;j<n;j++)
            catalan[i]=(catalan[i]+(catalan[j]*catalan[i-1-j])%R)%R;
    }
}
void solve2(){
    Prepare();
    f[0][0]=1;
    a[0]=-inf;
    for (int i=1;i<=2*n;i++)
        for (int j=i%2;j<=min(n,i);j++){
            f[i][j]=f[i-1][j-1];
            int k=lower_bound(a.begin(),a.end(),a[i]-m)-a.begin();
            if (k>0&&k<i){
                if (k%2==i%2)k++;
                for (;k<i;k+=2)
                    (f[i][j]+=(f[k-1][j]*catalan[(i-k-1)/2])%R)%=R;
            }
        }
    cout<<f[2*n][0];
}
int main()
{
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    scanf("%d%d",&n,&m);
    a.push_back(-inf);
    int x;
    for (int i=1;i<=2*n;i++)scanf("%d",&x),a.push_back(x);
//    solve2();
    if (a[2*n]-a[1]<=m)solve1();
    else solve2();
    return 0;
}
