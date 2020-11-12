#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

#define maxN 300002
#define maxK 16
#define MAX_TOP (maxn)15

typedef long maxn;
typedef long long maxa;

maxa INF = 1e17;

struct Top {
    maxa value[maxK];

    Top() {
        for(maxn i = 0; i < MAX_TOP; i++) value[i] = -INF;
    }

    maxa& operator [] (const maxn x) {
        return value[x];
    }
    maxa operator [] (const maxn x) const {
        return value[x];
    }

    void Update(const maxa x) {
        for(maxn i = 0; i < MAX_TOP; i++) {
            if (value[i] == -INF) break;
            value[i] += x;
        }
    }

    static Top Merge(const Top &a, const Top &b, const maxn need = MAX_TOP) {
        Top res;
        maxn xa = 0, xb = 0;
        for(maxn i = 0; i < need; i++) res[i] = a[xa] > b[xb]? a[xa++] : b[xb++];
        return res;
    }
};


class SegmentTree {
private:
    std::vector <Top> top;
    std::vector <maxa> lazy;
    maxn n;

    void Init(const maxn i, const maxn l, const maxn r) {
        if (l > r) return;
        for(maxn j = 0; j < std::min(r - l + 1, MAX_TOP); j++) top[i][j] = 0;
        if (l == r) return;

        maxn m = (l + r) >> 1;
        Init(2*i, l, m);
        Init(2*i + 1, m + 1, r);
    }

    void apply(const maxn i, const maxa x) {
        top[i].Update(x);
        lazy[i] += x;
    }

    void pushDown(const maxn i) {
        apply(2*i, lazy[i]);
        apply(2*i + 1, lazy[i]);
        lazy[i] = 0;
    }

    void Update(const maxn i, const maxn L, const maxn R, const maxn Lq, const maxn Rq, const maxa x) {
        if (L > Rq || R < Lq || L > R || Lq > Rq) return;
        if (L  >= Lq && R <= Rq) return apply(i, x);

        pushDown(i);
        maxn m = (L + R) >> 1;
        Update(2*i, L, m, Lq, Rq, x);
        Update(2*i + 1, m + 1, R, Lq, Rq, x);

        top[i] = Top::Merge(top[2*i], top[2*i + 1]);
    }

    Top GetPos(const maxn i, const maxn L, const maxn R, const maxn Lq, const maxn Rq, const maxn pos) {
        if (L > Rq || R < Lq || L > R || Lq > Rq) return Top();
        if (L  >= Lq && R <= Rq) return top[i];

        pushDown(i);
        maxn m = (L + R) >> 1;
        Top topL = GetPos(2*i, L, m, Lq, Rq, pos);
        Top topR = GetPos(2*i + 1, m + 1, R, Lq, Rq, pos);

        return Top::Merge(topL, topR, pos);
    }

public:
    SegmentTree(const maxn n = 0) {
        this->n = n;
        if (n > 0) {
            top.assign(4*n + 7, Top());
            lazy.assign(4*n + 7, 0);
            Init(1, 1, n);
        }
    }

    void Update(const maxn L, const maxn R, const maxa x) {
        Update(1, 1, n, L, R, x);
    }

    maxa getValue(const maxn pos) {
        maxn i = 1, L = 1, R = n;
        while (L != R) {
            pushDown(i);

            maxn m = (L + R) >> 1;
            if (pos <= m) 
                i = 2*i, R = m;
            else 
                i = 2*i + 1, L = m + 1;
        }
        return top[i][0];
    }

    Top getPos(const maxn L, const maxn R, const maxn pos) {
        return GetPos(1, 1, n, L, R, pos);
    }
};


maxn n, st[2][maxN], en[2][maxN], parity[maxN], parityCount[2], treeSize[maxN];
std::vector <maxn> ad[maxN];
SegmentTree seg[2];
int subtask;


void Prepare() {
    std::cin >> subtask >> n;

    for(maxn v = 2, u; v <= n; v++) {
        std::cin >> u;
        ad[u].push_back(v);
    }
}


void DFS(const maxn u, const maxn pari) {
    st[0][u] = parityCount[0] + 1;
    st[1][u] = parityCount[1] + 1;
    parity[u] = pari;
    ++parityCount[pari];

    treeSize[u] = 1;
    for(maxn i = 0; i < ad[u].size(); i++) {
        const maxn v = ad[u][i];
        DFS(v, pari ^ 1);
        treeSize[u] += treeSize[v];
    }

    en[0][u] = parityCount[0];
    en[1][u] = parityCount[1];
}


void Update(const maxn idx, const maxa x) {
    seg[0].Update(st[0][idx], en[0][idx], parity[idx] == 0? x : -x);
    seg[1].Update(st[1][idx], en[1][idx], parity[idx] == 1? x : -x);
}


maxa GetValue(const maxn idx) {
    return seg[parity[idx]].getValue(st[parity[idx]][idx]);
}


maxa GetPos(const maxn root, const maxn pos) {
    if (treeSize[root] < pos) return 0;

    Top top[2];
    top[0] = seg[0].getPos(st[0][root], en[0][root], pos);
    top[1] = seg[1].getPos(st[1][root], en[1][root], pos);

    return Top::Merge(top[0], top[1], pos)[pos - 1];
}


void Process() {
    DFS(1, 0);
    seg[0] = SegmentTree(parityCount[0]);
    seg[1] = SegmentTree(parityCount[1]);

    maxn Q; std::cin >> Q;
    while (Q--) {
        std::string opt;
        maxn u;
        std::cin >> opt;

        switch (opt[0])
        {
        case 'a':
            maxa x;
            std::cin >> u >> x;
            Update(u, x);
            break;
        
        case 'g':
            std::cin >> u;
            std::cout << GetValue(u) << ' ';
            break;

        case 'p':
            maxn pos;
            std::cin >> u >> pos;
            std::cout << GetPos(u, pos) << ' ';

        default:
            break;
        }
    }
}


int main() {
    freopen("query.inp", "r", stdin);
    freopen("query.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}