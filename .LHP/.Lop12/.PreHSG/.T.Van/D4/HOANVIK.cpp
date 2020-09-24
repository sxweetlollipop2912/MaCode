#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 10

typedef int maxn;

maxn n, k, res;
std::vector <maxn> v;


void Prepare() {
    std::cin >> n >> k;
}


void Process() {
    for(maxn i = 1; i <= n; i++) v.push_back(i);

    res = 0;
    do {
        for(maxn i = 1; i < n; i++)
            if (std::abs(v[i] - v[i - 1]) > k) {
                --res;
                break;
            }
        ++res;
    } while (std::next_permutation(v.begin(), v.end()));

    std::cout << res;
}


int main() {
    freopen("hoanvik.inp", "r", stdin);
    freopen("hoanvik.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
