#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#define mp make_pair
using namespace std;

const int N = 305 + 305, inf = 1e9;
int n, a[N], b[N], d[N], m, f[N][N], ma;
map<int, int> Map;

int main()
{
    freopen("BANTAU.inp","r",stdin);
    freopen("BANTAU.out","w",stdout);

    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        scanf("%d%d%d",a+i,b+i,d+i);
        Map[a[i]] = Map[b[i]] = 0;
    }
    m = 0;
    for(auto &x: Map) x.second = ++m;
    for(int i=1; i<=n; ++i) {
        a[i] = Map[a[i]];
        b[i] = Map[b[i]];
    }

    for(int i=m,l,r; i>=1; --i) for(int j=i; j<=m; ++j) {
        f[i][j] = inf; ma = 0; l = r = i;
        for(int z=1; z<=n; ++z) if (i<=a[z] && b[z]<=j && d[z] > ma) {
            ma = d[z]; l = a[z]; r = b[z];
        }
        for(int u=l; u<=r; ++u) f[i][j] = min(f[i][j], ma + f[i][u-1] + f[u+1][j]);
    }
    printf("%d",f[1][m]);
}
