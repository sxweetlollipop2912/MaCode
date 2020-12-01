#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5+5;
int n, m, k, ans, d, ns, b[N];
char s[N], t[N], inp[N], a[N];

void push(char c, int tmp)
{
    if (ns > 0 && a[ns] == c) b[ns] += tmp;
        else a[++ns] = c, b[ns] = tmp;
}
int pop(char c)
{
    return a[ns] == c ? b[ns--] : 0;
}
void Enter(char s[], int &n)
{
    int t1, t2; scanf("%s",inp); k = strlen(inp); ns = 0;

    for(int i=0; i<k; ++i)
    if (inp[i] == 'L') {
        t1 = pop('1'); t2 = pop('2');
        if (t2 > 1) push('2', t2-1);
        push('1', 1); if (t1 > 0) push('2', t1);
    } else
    if (inp[i] == 'R') {
        t1 = pop('2'); t2 = pop('1');
        if (t2 > 1) push('1', t2-1);
        push('2', 1); if (t1 > 0) push('1', t1);
    } else
    if (inp[i] == 'U') {
        if (--b[ns] == 0) --ns;
    } else push(inp[i], 1);

    for(int i=1; i<=ns; ++i) while (b[i]--) s[++n] = a[i];
}
int main()
{
    freopen("LYRA.inp","r",stdin);
    freopen("LYRA.out","w",stdout);

    Enter(s, n); Enter(t, m);
    k = 1; while (k<=n && k<=m && s[k] == t[k]) ++k;
    if (k>n || k>m) {printf("%d",max(n-m, m-n)); return 0;}
    if (s[k] > t[k]) {
        for(int i=1; i<=n; ++i) inp[i] = s[i];
        for(int i=1; i<=m; ++i) s[i] = t[i];
        for(int i=1; i<=n; ++i) t[i] = inp[i];
        swap(n, m);
    }

    ans = n+m - 2*k + 1; d = 0;
    for(int i=k+1; i<=n && i<=m; ++i) {
        d = d+d + (s[i]=='1') + (t[i]=='2');
        ans = min(ans, n-i + m-i + d+1);
        if (ans < d) break;
    }
    printf("%d",ans);
}
