#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>

#define maxN 200002
#define en first
#define st second

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> p_t;

maxn n, K, res;
p_t a[maxN];
std::multiset <maxa> set;


void Prepare() {
    std::cin >> n >> K;
    for(maxn i = 0; i < n; i++) std::cin >> a[i].st >> a[i].en;
    std::sort(a, a + n);
}


void Process() {
    for(maxn i = 0; i < K; i++) set.insert(-a[i].en);
    res = K;

    for(maxn i = K; i < n; i++) {
        std::set <maxa>::iterator it = set.lower_bound(-a[i].st);
        if (it == set.end()) continue;
        set.erase(it);
        set.insert(-a[i].en); ++res;
    }

    std::cout << res;
}


int main() {
    freopen("dauthu.inp", "r", stdin);
    freopen("dauthu.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
