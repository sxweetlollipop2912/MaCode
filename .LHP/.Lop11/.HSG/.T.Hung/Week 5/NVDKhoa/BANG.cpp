#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e3+5;
int n, k, num, a[N], b[N], x[N], y[N], ans, tmp;

int main()
{
    freopen("BANG.inp","r",stdin);
    freopen("BANG.out","w",stdout);

    scanf("%d%d",&n,&k);
    for(int i=1; i<=k; ++i) {
        scanf("%d%d%d",&num,a+i,b+i);
        --num; --a[i]; --b[i];
        x[i] = num / n; y[i] = num % n;
    }

    for(int i=1; i<=k; ++i) {
        ans = 0;
        tmp = (b[i] - y[i] + n) % n; ans += tmp;
        for(int j=1; j<=k; ++j) if (x[j] == x[i]) y[j] = (y[j] + tmp) % n;
        tmp = (a[i] - x[i] + n) % n; ans += tmp;
        for(int j=1; j<=k; ++j) if (y[j] == y[i]) x[j] = (x[j] + tmp) % n;
        printf("%d\n",ans);
    }
}
