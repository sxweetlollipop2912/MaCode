// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
 
#define maxN 200001
#define maxA 600004

typedef long maxn, maxa;
 
struct Line {
    maxa u, l, r;
    bool Ox;
 
    Line(maxa u = -1, maxa l = -1, maxa r = -1, bool Ox = false) {
        if (l > r) std::swap(l, r);
        this->u = u, this->l = l, this->r = r, this->Ox = Ox;
    }
};
 
maxn nx, ny, bit[maxA], resY;
maxa mxL;
Line X[maxN], Y[maxN];
std::vector <maxa> stX[maxA], enX[maxA], rX, rY;
std::vector <maxn> inX[maxA];
int opt;

 
void Prepare() {
    std::cin >> opt >> nx >> ny;
 
    for(maxn i = 0; i < nx; i++) {
        maxa y, l, r;
        std::cin >> y >> l >> r;
        X[i] = Line(y, l, r, 1);
        mxL = std::max(mxL, r - l + 1);
    }
    for(maxn i = 0; i < ny; i++) {
        maxa x, l, r;
        std::cin >> x >> l >> r;
        Y[i] = Line(x, l, r, 0);
        mxL = std::max(mxL, r - l + 1);
    }
}
 
 
void update(maxn bit[], const maxa n, maxa idx, const maxn x) {
    for(; idx <= n; idx += (idx & (-idx))) bit[idx] += x;
}
 
maxn sum(maxn bit[], const maxa n, maxa idx) {
    maxn re = 0;
    for(; idx > 0; idx -= (idx & (-idx))) re += bit[idx];
    return re;
}


maxn Idx(std::vector <maxa> &v, const maxa x) {
    return std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
 
 
void Init(const maxa R) {
    for(maxn i = 1; i <= rX.size(); i++) {
        stX[i].clear(); enX[i].clear(); inX[i].clear();
    }
    std::fill(bit + 1, bit + rY.size() + 1, 0);
    rX.clear(); rY.clear();

    for(maxn i = 0; i < nx; i++) {
        maxa y = X[i].u, l = X[i].l + R, r = X[i].r - R;
        if (l > r) continue;
        rX.push_back(l); rX.push_back(r + 1); rY.push_back(y);
    }
    for(maxn i = 0; i < ny; i++) {
        maxa x = Y[i].u, l = Y[i].l + R, r = Y[i].r - R;
        if (l > r) continue;
        rX.push_back(x); rY.push_back(l); rY.push_back(r);
    }

    std::sort(rX.begin(), rX.end());
    std::sort(rY.begin(), rY.end());
    rX.resize(std::unique(rX.begin(), rX.end()) - rX.begin());
    rY.resize(std::unique(rY.begin(), rY.end()) - rY.begin());
 
    for(maxn i = 0; i < nx; i++) {
        maxa l = X[i].l + R, r = X[i].r - R; maxn y = Idx(rY, X[i].u);
        if (l > r) continue;
        stX[Idx(rX, l)].push_back(y);
        enX[Idx(rX, r + 1)].push_back(y);
    }
    for(maxn i = 0; i < ny; i++) {
        maxa x = Y[i].u, l = Y[i].l + R, r = Y[i].r - R;
        if (l > r) continue;
        inX[Idx(rX, x)].push_back(i);
    }
}
 
 
bool Check(const maxa R) {
    Init(R);
 
    for(maxa x = 1; x <= rX.size(); x++) {
        for(maxn i = 0; i < stX[x].size(); i++) update(bit, rY.size(), stX[x][i], 1);
        for(maxn i = 0; i < enX[x].size(); i++) update(bit, rY.size(), enX[x][i], -1);
 
        for(maxn i = 0; i < inX[x].size(); i++) {
            maxn l = Idx(rY, Y[inX[x][i]].l + R),
                 r = Idx(rY, Y[inX[x][i]].r - R);
            if (sum(bit, rY.size(), r) - sum(bit, rY.size(), l - 1) == 0) continue;
            resY = inX[x][i];
            return 1;
        }
    }
 
    return 0;
}
 
 
void Process() {
    maxa L = 0, R = mxL;
    while (L != R) {
        maxa m = (L + R + 1) / 2;
        if (Check(m)) L = m;
        else R = m - 1;
    }
 
    Check(L);
    std::cout << L << ' ';
    
    for(maxn i = 0; i < nx; i++) {
        maxa x = Y[resY].u, yl = Y[resY].l, yr = Y[resY].r, y = X[i].u, l = X[i].l, r = X[i].r;
        if (y - yl < L || yr - y < L || x - l < L || r - x < L) continue;
        std::cout << i + 1 << ' ' << resY + 1;
        return;
    }
}
 
 
int main() {
    freopen("collider.inp", "r", stdin);
    freopen("collider.out", "w", stdout);
 
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
 
    Prepare();
    Process();
}
