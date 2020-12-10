#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 200002

typedef long maxn;
typedef long long maxa;

const maxn N = 200000;

maxn n, sum[maxN], l, r;
maxa X;
bool a[maxN];


void Prepare() {
    std::cin >> n >> X;

    for(maxn i = 1; i <= n; i++) {
        maxa x; std::cin >> x;
        a[i] = x >= X;
        sum[i] = sum[i - 1] + a[i];
    }
    l = 1, r = n;
}


void Process() {
    maxn Q; std::cin >> Q;
    while (Q--) {
        int opt; std::cin >> opt;

        if (opt == 1) {
            maxa x; std::cin >> x;
            ++r; a[r] = x >= X; sum[r] = sum[r - 1] + a[r];
        }
        if (opt == 2) {
            ++l;
        }
        if (opt == 3) {
            maxn idx; std::cin >> idx; idx += l;
            std::cout << sum[idx] - sum[l - 1] - a[idx] << '\n';
        }
    }
}


int main() {
    freopen("queue.inp", "r", stdin);
    freopen("queue.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
