#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define mize(a, b) a = min(a, b)
#define maxi(a, b) a = max(a, b)
using namespace std;

const int N = 405;
int n, m, a[N]; char c[N];
int64_t f[N][N][2], inf = 1e18;

int main()
{
    freopen("MATKHAU.inp","r",stdin);
    freopen("MATKHAU.out","w",stdout);

    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d %c",a+i,c+i);
    for(int i=1; i<=n; ++i) a[n+i] = a[i], c[n+i] = c[i];

    m = n+n; /// 0 min, 1 max
    for(int i=1; i<=m; ++i)
        f[i][i][0] = f[i][i][1] = a[i];

    for(int i=m-1; i>=1; --i) for(int j=i+1; j<=m; ++j) {
        f[i][j][0] = inf; f[i][j][1] =-inf; for(int k=i; k<j; ++k) {
            if (c[k] == '+' || c[k] == '?') {
                mize(f[i][j][0], f[i][k][0] + f[k+1][j][0]);
                maxi(f[i][j][1], f[i][k][1] + f[k+1][j][1]);
            }
            if (c[k] == '-' || c[k] == '?') {
                mize(f[i][j][0], f[i][k][0] - f[k+1][j][1]);
                maxi(f[i][j][1], f[i][k][1] - f[k+1][j][0]);
            }
            if (c[k] == '*' || c[k] == '?') {
                for(int x=0; x<=1; ++x) for(int y=0; y<=1; ++y)
                mize(f[i][j][0], f[i][k][x] * f[k+1][j][y]),
                maxi(f[i][j][1], f[i][k][x] * f[k+1][j][y]);
            }
        }
    }

    for(int i=1; i<=n; ++i) printf("%lld%lld",abs(f[i][i+n-1][0]),abs(f[i][i+n-1][1]));
}
