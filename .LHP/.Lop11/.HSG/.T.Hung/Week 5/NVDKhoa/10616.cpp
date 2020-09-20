#include <iostream>
#include <cstdio>
using namespace std;

const int N = 205;
int n, q, query, T, a[N], m, mod, vis[N][15][25], ver, b[N];
int64_t f[N][15][25];

int64_t F(int n,int m,int d)
{
    if (m < 0) return 0; if (n == 0) return m == 0 && d == 0;
    if (vis[n][m][d] == ver) return f[n][m][d]; vis[n][m][d] = ver;
    return f[n][m][d] = F(n-1, m, d) + F(n-1, m-1, (d-b[n]+mod) % mod);
}
int main()
{
    freopen("10616.inp","r",stdin);
    freopen("10616.out","w",stdout);

    while (scanf("%d%d",&n,&q), n) {
        query = 0;
        for(int i=1; i<=n; ++i) scanf("%d",a+i);
        printf("SET %d:\n",++T);
        for(int i=1; i<=q; ++i) {
            query += 1; ver += 1; scanf("%d%d",&mod,&m);
            for(int j=1; j<=n; ++j) b[j] = (a[j]%mod + mod) % mod;
            printf("QUERY %d: %lld\n",query,F(n, m, 0));
        }
    }
}
