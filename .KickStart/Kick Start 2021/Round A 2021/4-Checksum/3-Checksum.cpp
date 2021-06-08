// 3-Checksum
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

#define maxN 501
#define R first
#define C second

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxn, maxn> p_t;

maxn n, CNT;
maxa B[maxN][maxN], res;
bool done[maxN][maxN];
std::set <p_t> r[maxN], c[maxN];
std::queue <p_t> q;


class cmp {
public:
    bool operator()(const p_t p1,  const p_t p2) {
        return B[p1.R][p1.C] > B[p2.R][p2.C];
    }
};
std::priority_queue <p_t, std::vector <p_t>, cmp> pq;


void Init() {
    CNT = 0;
    res = 0;
    for(maxn i = 0; i < n; i++) {
        r[i].clear();
        c[i].clear();
        std::fill(done[i], done[i] + n, 0);
    }
    q = std::queue <p_t>();
    pq = std::priority_queue <p_t, std::vector <p_t>, cmp>();
}


void Prepare() {
    std::cin >> n;

    CNT = 0;
    for(maxn i = 0; i < n; i++) for(maxn j = 0; j < n; j++) {
        maxn a; std::cin >> a;
        if (a == -1) {
            r[i].insert(p_t(i, j));
            c[j].insert(p_t(i, j));
            ++CNT;
        }
        else done[i][j] = 1;
    }

    for(maxn i = 0; i < n; i++) for(maxn j = 0; j < n; j++) {
        std::cin >> B[i][j];
        if (!done[i][j]) pq.push(p_t(i, j));
    }

    //for(maxn i = 0; i < 2; i++) for(maxn j = 0; j < n; j++) { maxn x; std::cin >> x; }
}


bool Push(const p_t p) {
    if (done[p.R][p.C]) return 0;
    q.push(p);
    r[p.R].erase(p); c[p.C].erase(p); done[p.R][p.C] = 1;
    return 1;
}


void Process() {
    res = 0;
    while (CNT) {
        for(maxn i = 0; i < n; i++) {
            if (r[i].size() == 1) {
                p_t p = *r[i].begin();
                if (Push(p)) break;
            }
            if (c[i].size() == 1) {
                p_t p = *c[i].begin();
                if (Push(p)) break;
            }
        }
        if (q.empty()) {
            while (!Push(pq.top())) pq.pop();
            p_t p = pq.top(); pq.pop();
            res += B[p.R][p.C];
        }
        while (!q.empty()) {
            p_t p = q.front(); q.pop(); --CNT;

            if (r[p.R].size() == 1) {
                p_t p1 = *r[p.R].begin();
                Push(p1);
            }
            if (c[p.C].size() == 1) {
                p_t p1 = *c[p.C].begin();
                Push(p1);
            }
        }
    }

    std::cout << res << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    for(int i = 1; i <= t; i++) {
        std::cout << "Case #" << i << ": ";
        Init();
        Prepare();
        Process();
    }
}