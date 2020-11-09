#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <math.h>

#define maxN 1002
#define n first
#define k second

typedef long long maxa;
typedef std::pair <maxa, maxa> C_t;


maxa C(maxa n, const maxa k, const maxa LIM) {
    if (n < k) return -1;

    maxa re = 1, i;
    std::set <maxa> set;

    for(i = 0; i < k; i++, n--){
        maxa n1 = n;
        for(maxa j = k; j >= 2; j--)
            if (set.find(j) == set.end() && n1 % j == 0) {
                n1 /= j;
                set.insert(j);
            }
        if (log10(re) + log10(n1) > 16) break;
        re *= n1;
    }

    return i < k || re > LIM? -1 : re;
}


C_t BS(const maxa X) {
    for(maxa K = 2; K <= 30; K++) {
        maxa l = 2 * K, r = 100000000;
        
        while (l < r) {
            maxa m = (l + r) / 2;
            maxa re = C(m, K, X);

            if (re == X) return C_t(m, K);
            if (re == -1) r = m;
            else l = m + 1;
        }

        if (C(l, K, X) == X) return C_t(l, K);
    }

    return C_t(0, 0);
}


void Process() {
    int t; std::cin >> t;
    while (t--) {
        maxa x; std::cin >> x;
        C_t res = BS(x);
        std::cout << res.n << ' ' << res.k << '\n';
    }
}


int main() {
    freopen("dangtri.inp", "r", stdin);
    freopen("dangtri.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Process();
}