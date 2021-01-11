#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 200002

typedef long maxn;

maxn n, m, pos[maxN], lvl[maxN], bit[maxN], N;


void Init() {
    std::fill(pos, pos + maxN, 0);
    std::fill(lvl, lvl + maxN, 0);
    std::fill(bit, bit + maxN, 0);
    N = 0;
}


void Prepare() {
    std::cin >> n >> m;
    N = n + m;
    for(maxn id = 1, idx = n; id <= n; id++, idx--) pos[id] = idx, lvl[idx] = id - 1;
}


void Update(maxn bit[], const maxn idx, const maxn n, const maxn X) {
    for(maxn i = idx; i <= n; i += i & (-i))
        bit[i] += X;
}

maxn Sum(maxn bit[], const maxn idx) {
    maxn re = 0;
    for(maxn i = idx; i > 0; i -= i & (-i))
        re += bit[i];
    return re;
}


void Process() {
    for(maxn im = 0, curN = n; im < m; im++) {
        maxn id; std::cin >> id;
        //std::cout << '\n' << id << ' ' << pos[id] << ' ' << Sum(bit, pos[id]) << '\n';
        std::cout << Sum(bit, pos[id]) + lvl[pos[id]] << ' ';

        Update(bit, pos[id], N, 1);
        ++curN;
        pos[id] = curN, lvl[curN] = 0;
        //std::cout << "Sum " << Sum(bit, 5) << ' ' << curN << '\n';
        Update(bit, curN, N, -1);
    }
    std::cout << '\n';
}


int main() {
    freopen("bstp.inp", "r", stdin);
    freopen("bstp.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Init();
        Prepare();
        Process();
    }
}
