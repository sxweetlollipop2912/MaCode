#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 100002

typedef long maxn, maxt;
typedef long long maxa;
typedef std::pair <maxt, maxn> res_t;

maxn n, idx[maxN];
maxa a[maxN], res_a;
maxt t[maxN], A, B;
std::vector <res_t> res;


bool cmp(const maxn &x, const maxn &y) {
    return t[x] < t[y];
}

void Prepare() {
    std::cin >> n >> A >> B;
    for(maxn i = 0; i < n; i++) std::cin >> t[i] >> a[i], idx[i] = i;
    t[n] = B + 1, a[n] = 0, idx[n] = n;
    std::sort(idx, idx + n + 1, cmp);
}


class cmp_pq {
public:
    bool operator()(const maxn &x, const maxn &y) {
        return a[x] < a[y];
    }
};
std::priority_queue <maxn, std::vector <maxn>, cmp_pq> pq;


void Process() {
    maxn i = 0;
    while (t[idx[i]] <= A) pq.push(idx[i]);

    for(maxt T = A - 1; T <= B && i <= n; i++) {
        maxt Tcur = std::min(B + 1, t[idx[i]]);

        for(T = T + 1; T < Tcur && !pq.empty(); T++) {
            //std::cout << i << ' ' << T << ' '<< pq.top() << '\n';
            res.push_back(res_t(T, pq.top() + 1));
            res_a += a[pq.top()]; pq.pop();
        }

        T = Tcur;
        if (t[idx[i]] > B) break;
        pq.push(idx[i]);
        for(; i < n && t[idx[i]] == t[idx[i + 1]]; i++) pq.push(idx[i + 1]);
        //std::cout << i << ' ' << T << ' '<< pq.top() << '\n';
        res.push_back(res_t(T, pq.top() + 1));
        res_a += a[pq.top()]; pq.pop();
    }

    std::cout << res_a << '\n';
    for(maxn i = 0; i < res.size(); i++) std::cout << res[i].first << ' ' <<res[i].second << '\n';
}


int main() {
    freopen("diamond.inp", "r", stdin);
    freopen("diamond.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
