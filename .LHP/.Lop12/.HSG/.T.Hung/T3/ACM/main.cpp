#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 100002
#define N 3

typedef long maxn;
typedef long long maxa;

const maxa INF = 99999999999999999;

maxn n;
maxa a[3][maxN], f[3][maxN], res;


void Prepare() {
    std::cin >> n;
    for(int in = 0; in < N; in++) for(maxn i = 1; i <= n; i++) std::cin >> a[in][i];
}


maxa DP(std::vector <int> &v) {
    for(int i = 0; i < N; i++) std::fill(f[i] + 1, f[i] + n + 1, INF);

    for(maxn i = 1; i <= n; i++) f[v[0]][i] = a[v[0]][i] + f[v[0]][i - 1];

    for(int iv = 1; iv < N; iv++) {
        maxn in = v[iv], in_prev = v[iv - 1];
        f[in][iv + 1] = f[in_prev][iv] + a[in][iv + 1];
        for(maxn i = iv + 2; i <= n; i++) {
            f[in][i] = std::min(f[in][i - 1], f[in_prev][i - 1]) + a[in][i];
        }
    }

    return f[v[N - 1]][n];
}


void Process() {
    std::vector <int> v{ 0,1,2 };
    res = INF;

    do {
        res = std::min(res, DP(v));
    } while (std::next_permutation(v.begin(), v.end()));

    std::cout << res;
}


int main() {
    freopen("acm.inp", "r", stdin);
    freopen("acm.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
