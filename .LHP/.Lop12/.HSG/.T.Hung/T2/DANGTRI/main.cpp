#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <math.h>
#include <vector>

#define maxN 1002
#define N first
#define K second

typedef long long maxa;
typedef std::pair <maxa, maxa> C_t;
typedef std::multiset <maxa> set_t;

std::vector <C_t> res;


maxa C(maxa n, const maxa k, const maxa LIM) {
    if (n < k) return -1;

    maxa re = 1;
    set_t set;
    for(maxa i = 0; i < k; i++, n--) set.insert(n);

    std::vector <maxa> v;
    for(maxa i = 2, x = i; i <= k; i++, x = i) {
        for(maxa p = 2; x != 1; p++)
            while (x % p == 0) {
                v.push_back(p); x /= p;
            }
    }
    std::sort(v.begin(), v.end(), std::greater <maxa>());

    for(maxa vi = 0; vi < v.size(); vi++) {
        maxa i = v[vi];
        for(set_t::iterator it = set.begin(); it != set.end(); it++) {
            maxa j = *it;
            if (j % i != 0) continue;
            set.erase(it);
            if (j != i) set.insert(j / i);
            break;
        }
    }

    for(set_t::iterator it = set.begin(); it != set.end(); it++) {
        maxa j = *it;
        if (log10(re) + log10(j) > 16) return -1;
        re *= j;
    }

    return re > LIM? -1 : re;
}


void BS(const maxa X) {
    for(maxa K = 1; K <= 30; K++) {
        maxa l = K, r = 1000000000000000;

        while (l < r) {
            maxa m = (l + r) / 2;
            maxa re = C(m, K, X);

            if (re == X) {
                res.push_back(C_t(m, K));
                break;
            }
            if (re == -1) r = m;
            else l = m + 1;
        }

        if (C(l, K, X) == X && res.back() != C_t(l, K)) res.push_back(C_t(l, K));
    }
}


void Process() {
    int t; std::cin >> t;
    while (t--) {
        res.clear();
        maxa x; std::cin >> x;
        BS(x);
        std::sort(res.begin(), res.end());

        std::cout << res.size() << '\n';
        for(maxa i = 0; i < res.size(); i++)
            std::cout << "(" << res[i].N << "," << res[i].K << ") ";
        std::cout << '\n';
    }
}


int main() {
    freopen("dangtri.inp", "r", stdin);
    freopen("dangtri.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Process();
}
