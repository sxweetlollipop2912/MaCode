#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5+5;
int n, m, a[N], len, i, j, ans[12], x;
int h1, m1, s1, h2, m2, s2, l, r;
int64_t s[N], sum;

void Print(int frac)
{
    for( j=0; j<=frac+1; ++j) {
        ans[j] = sum / len;
        sum = sum%len * 10;
    }

    x = (ans[frac+1] >= 5);
    for( j=frac; j>0 && x>0; --j) if (ans[j] == 9)
        ans[j] = 0; else x = 0, ans[j] += 1;
    if (x) ans[0] += 1;

    printf("%d.",ans[0]);
    for( j=1; j<=frac; ++j) printf("%d",ans[j]);
    puts("");
}
int main()
{
    freopen("QUANGCAO.inp","r",stdin);
    freopen("QUANGCAO.out","w",stdout);

    scanf("%d",&n);
    for( i=1; i<=n; ++i) {
        scanf("%d%*c%d%*c%d %*c %d%*c%d%*c%d",&h1,&m1,&s1,&h2,&m2,&s2);
        l = s1 + 60 * (m1 + 60 * h1); r = s2 + 60 * (m2 + 60 * h2);
        a[l] += 1; a[r+1] -= 1; if (l > r) a[0] += 1;
    }

    m = 59 + 60 * (59 + 60 * 23); s[0] = a[0];
    for( i=1; i<=m; ++i) a[i] += a[i-1], s[i] = s[i-1] + a[i];

    scanf("%d",&n);
    for( i=1; i<=n; ++i) {
        scanf("%d%*c%d%*c%d %*c %d%*c%d%*c%d",&h1,&m1,&s1,&h2,&m2,&s2);
        l = s1 + 60 * (m1 + 60 * h1); r = s2 + 60 * (m2 + 60 * h2);

        len = r-l+1; sum = s[r] - (l>0 ? s[l-1] : 0);
        if (l > r) len += m, sum += s[m]; Print(5);
    }
}
