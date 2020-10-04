#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1001

typedef int maxn;
typedef long long maxa;

maxn n;
maxa v[maxN], res;


void Prepare() {
    std::cin >> n;
    for (maxn i = 0; i < n; i++) std::cin >> v[i];
    std::sort(v, v + n);
}


void Process() {
    if (n == 1) {
        res = v[0];
    }
    else {
        maxa x = 2 * v[1] + v[0];
        res = v[1];
        for (maxn i = n - 1; i > 2; i -= 2)
            res += v[i] + x;
        if (n % 2 != 0)
            res += v[1] + v[0] + v[2] - v[1];
    }
    std::cout << "kq " << res << '\n';
}


int main() {
    //freopen("quacau.inp", "r", stdin);
    //freopen("quacau.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}