#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 200001
#define Idx first
#define Msg second

typedef long maxn, maxa;
typedef std::pair <maxn, maxa> pq_t;

maxn n, K;
maxa a[maxN];


void Prepare() {
    std::cin >> n >> K;
    for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


class cmp {
public:
    bool operator()(const pq_t& p1, const pq_t& p2) {
        return p1.Msg < p2.Msg || (p1.Msg == p2.Msg && p1.Idx > p2.Idx);
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


void Process() {
    for (maxn i = 0; i < n; i++) pq.push(pq_t(i, a[i]));
    while (K--) {
        std::cout << pq.top().Idx + 1 << ' ' << pq.top().Msg << '\n';
        pq.pop();
    }
}


int main() {
    freopen("topk.inp", "r", stdin);
    freopen("topk.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
