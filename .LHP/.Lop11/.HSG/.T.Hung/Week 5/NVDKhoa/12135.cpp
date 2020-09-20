#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int N = 15, M = 41, K = 1 << 15;
int n, m, a[M], k, ver, v[K], d[K], q, plot;

int main()
{
    freopen("12135.inp","r",stdin);
    freopen("12135.out","w",stdout);

    int T; scanf("%d",&T); for(int test=1; test<=T; ++test) {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; ++i) {
            a[i] = 0;
            scanf("%d",&k);
            for(int j; k>0; --k) {
                scanf("%d",&j);
                a[i] |= (1<<j);
            }
        }

        ++ver;
        queue<int> Q; Q.push(0); v[0] = ver;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(int i=1; i<=m; ++i) if (v[u ^ a[i]] < ver) {
                d[u ^ a[i]] = d[u] + 1;
                v[u ^ a[i]] = ver;
                Q.push(u ^ a[i]);
            }
        }

        printf("Case %d:\n",test);
        scanf("%d",&q); while (q--) {
            plot = 0;
            for(int i=n-1; i>=0; --i) {
                char c; scanf(" %c",&c);
                plot |= (c-'0') << i;
            }
            if (v[plot] == ver) printf("%d\n",d[plot]); else puts("-1");
        }
        puts("");
    }
}
