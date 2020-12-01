//D_br
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 22
#define maxB ((1 << 20) + 1)
#define B ((1 << 20) - 1)

typedef int maxn;
typedef long maxb;
typedef std::vector <maxn> dp_t;

maxn n, K, a[maxN];
bool done[maxN][maxB], fail[maxN][maxB];
dp_t f[maxN][maxB];


void Prepare() {
    std::cin >> n >> K;
    for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


bool DP(const maxn n, const maxn b) {
    if (b == 0) return 1;
    if (n == 0) return 0;
    if (done[n][b]) return !fail[n][b];
    done[n][b] = 1;
    fail[n][b] = 1;

    if (((b >> (a[n - 1] - 1)) & 1) && DP(n - 1, b - (1 << (a[n - 1] - 1)))) {
        f[n][b] = f[n - 1][b - (1 << (a[n - 1] - 1))];
        f[n][b].push_back(a[n - 1]);
    }
    //std::cout << "first " << n << ' ' << b << ' ' << f[n][b].size() << ' ' << (b - (1 << (a[n - 1] - 1))) << ' ' << f[n - 1][b - (1 << (a[n - 1] - 1))].size() << '\n';
    if (DP(n - 1, b) && (f[n][b].empty() || f[n][b] > f[n - 1][b]))
        f[n][b] = f[n - 1][b];

    if (!f[n][b].empty()) fail[n][b] = 0;
    //std::cout << n << ' ' << b << ' ' << f[n][b].size() << ' ' << !fail[n][b] << '\n';
    return !fail[n][b];
}


void Process() {
    DP(n, (1 << K) - 1);
    for (maxn i = 0; i < f[n][(1 << K) - 1].size(); i++)
        std::cout << f[n][(1 << K) - 1][i] << ' ';
}


int main() {
    freopen("D.inp", "r", stdin);
    freopen("D.ans", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}