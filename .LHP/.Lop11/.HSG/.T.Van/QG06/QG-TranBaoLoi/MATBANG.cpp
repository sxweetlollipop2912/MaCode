#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
short n,m,h[1011],k,w,l[1011],r[1011];
int ans;
int main(){
    freopen("MATBANG.inp","r",stdin);
    freopen("MATBANG.out","w",stdout);
    scanf("%hd%hd%hd%hd",&n,&m,&k,&w);
    short u;
    h[0]=h[m+1]=-1;
    for (short i=1;i<=n;++i){
        for (short j=1;j<=m;++j){
            scanf("%hd",&u);
            if (abs(u-k)<=w) ++h[j]; else h[j]=0;
        }
        for (short j=1;j<=m;++j) for (l[j]=j-1;h[j]<=h[l[j]];l[j]=l[l[j]]);
        for (short j=m;j;--j) for (r[j]=j+1;h[j]<=h[r[j]];r[j]=r[r[j]]);
        for (short j=1;j<=m;++j)
            ans=max(ans,(r[j]-l[j]-1)*(h[j]));
    }
    printf("%d",ans);
}
