#include <iostream>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#define maxn 100005
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
int n,m;
int Rank[maxn], cnt[maxn], par[maxn];
vector<pii> a;
int FindSet(int u)
{
    return (par[u]==u)? u : (par[u]=FindSet(par[u]));
}
void Union(int u, int v)
{
    if((u=FindSet(u))==(v=FindSet(v))) return;
    if (Rank[u]>=Rank[v]){
        cnt[par[u]]+=cnt[par[v]];
        par[v]=par[u];
        Rank[u]++;
    }
    else{
        cnt[par[v]]+=cnt[par[u]];
        par[u]=par[v];
        Rank[v]++;
    }
}
void nhap()
{
    int x,y;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>x>>y;
        ++x;++y;
        a.pb(pii(x,y));
    }
}
void xuly()
{
    for (int i=1;i<=n;i++)
        par[i]=i,cnt[i]=1;
    for (int i=0;i<m;i++){
        int x=a[i].fi;
        int y=a[i].se;
        Union(x,y);
        if (cnt[par[x]]==n) {
            cout<<i+1;
            return;
        }
    }
}
int main()
{
    freopen("LAMDUONG.INP","r",stdin);
    freopen("LAMDUONG.OUT","w",stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    nhap();
    xuly();
    return 0;
}
