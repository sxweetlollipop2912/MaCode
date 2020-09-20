#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#define pb push_back
#define fi first
#define se second
using namespace std;
int n,s,sum;
typedef pair<int,int> td;
td a[70007];
vector<int> ds;
int trace[70007];
bitset<70007> vis;
int ans[70007],nex[70007];
bool f[70007];
int main(){
    freopen("BagsCoins.inp","r",stdin);
    freopen("BagsCoins.out","w",stdout);
    scanf("%d%d",&n,&s);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i].fi),a[i].se=i;
        if (a[i].fi>s) {puts("-1");return 0;}
        sum+=a[i].fi;
    }
    if (sum<s) {puts("-1");return 0;}
    sort(a+1,a+1+n);
    if (a[n].fi>s) {puts("-1");return 0;}
    s-=a[n].fi;
    if (s==0){
        for (int i=1;i<=n;++i){
            if (i>1)  nex[a[i].se]=a[i-1].se;
            ans[a[i].se]=a[i].fi-a[i-1].fi;
        }
        for (int i=1;i<=n;++i){
            printf("%d",ans[i]);
            if (nex[i]) printf(" 1 %d\n",nex[i]);
            else printf(" 0\n");
        }
        return 0;
    }
    vis[0]=1;
    ds.pb(0);
    int tmp,id;
    for (int i=n-1;i>0;--i){
        for (int j=0,jj=ds.size();j<jj;++j){
            tmp=ds[j]+a[i].fi;
            if (tmp>s) continue;
            if (!vis[tmp]){
                vis[tmp]=1;
                ds.pb(tmp);
                trace[tmp]=i;
                if (tmp==s){
                    while(tmp){
                        ans[a[trace[tmp]].se]=a[trace[tmp]].fi;
                        f[a[trace[tmp]].se]=true;
                        tmp-=a[trace[tmp]].fi;
                    }
                    id=0;
                    for (int i=1;i<=n;++i)
                    if(!f[i]){
                        if (id)  nex[a[i].se]=a[id].se;
                        ans[a[i].se]=a[i].fi-a[id].fi;
                        id=i;
                    }
                    for (int i=1;i<=n;++i){
                        printf("%d",ans[i]);
                        if (nex[i]) printf(" 1 %d\n",nex[i]);
                        else printf(" 0\n");
                    }
                    return 0;
                }
            }
        }
    }
    puts("-1");
}
