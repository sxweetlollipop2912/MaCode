#include <iostream>
#include <cstdio>
#define Hash pair<unsigned int, int>
#define x first
#define y second
using namespace std;

const int N = 1e6+5, mod = 1e9+7;
int n, L[N], R[N], i, j, l, r, m;
char a[N], c[N];
Hash b[N], HR[N], HL[N];

Hash operator + (Hash a, int b) {
    return Hash(a.x+b, (a.y+b) % mod);
}
Hash operator * (Hash a, int b) {
    return Hash(a.x*b, 1LL*a.y*b % mod);
}
Hash operator - (Hash a, Hash b) {
    return Hash(a.x-b.x, (a.y-b.y+mod) % mod);
}
Hash operator * (Hash a, Hash b) {
    return Hash(a.x*b.x, 1LL*a.y*b.y % mod);
}

int main()
{
    freopen("BCL.inp","r",stdin);
    freopen("BCL.out","w",stdout);

    scanf("%d",&n);
    for( i=1; i<=n; ++i) scanf(" %c",&a[i]);
    for( i=1; i<=n; ++i) L[i] = (a[i-1] == a[i]) ? L[i-1] + 1 : 1;
    for( i=n; i>=1; --i) R[i] = (a[i+1] == a[i]) ? R[i+1] + 1 : 1;

    b[0].x = b[0].y = 1;
    for( i=1; i<=n; ++i) b[i] = b[i-1] * 26;
    for( i=n; i>=1; --i) HR[i] = HR[i+1] * b[1] + (a[i] - 'A');
    for( i=1; i<=n; ++i) HL[i] = HL[i-1] * b[1] + (a[i] - 'A');

    i = 1; j = n; n = 0;
    while (i <= j) {
        l = 1; r = j-i+1; while (l < r) { m = (l+r) >> 1;
            if (HR[i] - HR[i+m]*b[m] == HL[j] - HL[j-m]*b[m])
                l = m+1; else r = m;
        }
        c[++n] = (a[i+r-1] < a[j-r+1]) ? a[i++]  : a[j--];
    }

    c[n+1] = '\0'; printf("%s",c+1);
}
