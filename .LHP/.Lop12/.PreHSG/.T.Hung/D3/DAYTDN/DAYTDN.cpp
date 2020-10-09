#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1000002
#define N 1000000

typedef long maxn;
typedef long long maxt;

maxt K;
maxn f[maxN];


void Prepare() {
    std::cin >> K;
}


void Process() {
    if (!f[1]) {
        f[1] = 1, f[2] = 2;
        for(maxn i = 2, x = 2; i <= N; x++) for(maxn j = 0; j < f[x]; j++, i++) f[i] = x;
    }

    maxt t = 0;
    for(maxn i = 1; i <= N; i++) {
        if (t + f[i] > K) {
            std::cout << i << '\n';
            return;
        }
        t += f[i];
    }
}


int main() {
    freopen("daytdn.inp", "r", stdin);
    freopen("daytdn.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}