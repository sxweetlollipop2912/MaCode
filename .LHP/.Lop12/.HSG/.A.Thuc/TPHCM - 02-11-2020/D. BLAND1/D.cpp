// AC
#include <iostream>
#include <algorithm>
#include <deque>

#define maxN 301
#define maxA 1000000001

typedef int maxn;
typedef long maxa;

maxn m, n, res;
maxa K, a[maxN][maxN], mn[maxN], mx[maxN];


void Prepare() {
    std::cin >> m >> n >> K;
    for(maxn i = 0; i < m; i++) for(maxn j = 0; j < n; j++) std::cin >> a[i][j];
}


maxn Deque(const maxa mn[], const maxa mx[], const maxn n) {
    std::deque <maxn> dq_mn, dq_mx;
    maxn re = 0;

    for(maxn i = 0, l = 0; i < n; i++) {
        while (!dq_mn.empty() && mn[dq_mn.back()] >= mn[i]) dq_mn.pop_back();
        while (!dq_mx.empty() && mx[dq_mx.back()] <= mx[i]) dq_mx.pop_back();

        dq_mn.push_back(i);
        dq_mx.push_back(i);

        while (!dq_mn.empty() && !dq_mx.empty() && mx[dq_mx.front()] - mn[dq_mn.front()] > K) {
            l = std::min(dq_mx.front(), dq_mn.front()) + 1;
            while (!dq_mx.empty() && dq_mx.front() < l) dq_mx.pop_front();
            while (!dq_mn.empty() && dq_mn.front() < l) dq_mn.pop_front();
        }

        re = std::max(re, i - l + 1);
    }

    return re;
}


void Process() {
    res = 0;

    for(maxn l = 0; l < m; l++) {
        std::fill(mn, mn + n, maxA);
        std::fill(mx, mx + n, -maxA);
        for(maxn r = l; r < m; r++) {
            for(maxn j = 0; j < n; j++) {
                mn[j] = std::min(mn[j], a[r][j]);
                mx[j] = std::max(mx[j], a[r][j]);
            }
            res = std::max(res, (r - l + 1) * Deque(mn, mx, n));
        }
    }

    std::cout << res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}