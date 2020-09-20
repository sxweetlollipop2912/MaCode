#include <iostream>
#include <cstdio>
using namespace std;

const int N = 12, M = 1 << 12, inf = 300;
int n, ln[M], prob[M], ans, a[3][N], f[M][3];

int main()
{
    freopen("1240.inp","r",stdin);
    freopen("1240.out","w",stdout);

    n = 12;
    for(int i=0; i<n; ++i) ln[1<<i] = i;
    for(int k=1; k<(1<<n); ++k) for(int x=k; x>0; x-=x&-x) prob[k] += 1;

    int T; scanf("%d",&T); while (T--) {
        scanf("%d",&n); ans = 0;
        for(int i=0; i<3; ++i) for(int j=0; j<n; ++j) scanf("%d",&a[i][j]);

        for(int k=1; k<(1<<n); ++k) for(int i=0; i<3; ++i) f[k][i] = inf;
        for(int k=1; k<(1<<n); ++k) for(int i=0; i<3; ++i)  {
            for(int x=k; x>0; x-=x&-x) for(int u=0; u<3; ++u)
                if (i != u) f[k][i] = min(f[k][i], f[k^(x&-x)][u] + a[i][ln[x&-x]]);
            if (f[k][i] <= 280) ans = max(ans, prob[k]);
        }
        printf("%d\n",ans);
    }
}
