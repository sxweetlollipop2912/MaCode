// undone
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <set>

#define maxN 200002
#define maxS 400004
#define maxA 99999999999999999
#define Sum(l, r) (sum[r] - sum[l - 1])
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)
#define mid(L, R) (((L) + (R)) / 2)

typedef long maxn;
typedef long long maxa;

maxn n;
maxa M, a[maxN], sum[maxN], f[maxN], fm[maxN], min[maxS];
std::deque <maxn> dq;
std::multiset <maxa> set;


void Prepare() {
    std::cin >> n >> M;
    for (maxn i = 1; i <= n; i++) std::cin >> a[i];

    sum[1] = a[1];
    for (maxn i = 2; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    std::fill(min, min + maxS, maxA);
}


maxa Update(maxa seg[], const maxn Q, const maxa val, const maxn ids = 0, const maxn L = 0, const maxn R = n) {
    if (L > R) return maxA;
    //std::cout << "Upd " << L << ' ' << R << ' ' << ids << ' ' << seg[ids] << '\n';
    if (L > Q || R < Q) return seg[ids];
    if (L == R) return (seg[ids] = std::min(seg[ids], val));
    return (seg[ids] = std::min(Update(seg, Q, val, cle(ids), L, mid(L, R)), Update(seg, Q, val, cri(ids), mid(L, R) + 1, R))); 
}


maxa Min(maxa seg[], const maxn Lq, const maxn Rq, const maxn ids = 0, const maxn L = 0, const maxn R = n) {
    if (L > R || L > Rq || R < Lq) return maxA;
    //std::cout << "Min " << Lq << ' ' << Rq << ' ' << L << ' ' << R << ' ' << ids << ' ' << seg[ids] << '\n';
    if (L >= Lq && R <= Rq) return seg[ids];
    return std::min(Min(seg, Lq, Rq, cle(ids), L, mid(L, R)), Min(seg, Lq, Rq, cri(ids), mid(L, R) + 1, R));
}


void Process() {
    f[0] = fm[0] = 0;
    Update(min, 0, f[0]);
    f[1] = fm[1] = a[1];
    dq.push_front(1); set.insert(fm[1]); Update(min, 1, f[1]);

    for (maxn i = 2, j = 1; i <= n; i++) {
        while (Sum(j, i) > M) ++j;

        while (!dq.empty() && a[dq.front()] <= a[i]) {
            set.erase(fm[dq.front()]);
            dq.pop_front();
        }
        while (!dq.empty() && dq.back() < j) {
            set.erase(fm[dq.back()]);
            dq.pop_back();
        }

        maxn jj = dq.empty()? j : dq.front() + 1;

        fm[i] = a[i] + f[jj - 1];
        f[i] = maxA;
        if (!dq.empty()) f[i] = *set.begin();
        f[i] = std::min(f[i], Min(min, jj - 1, i - 1) + a[i]);

        std::cout << dq.size() << ' ' << set.size() << ' ' << f[i] << ' ' << fm[i] << '\n';

        Update(min, i, f[i]);
        dq.push_front(i); set.insert(fm[i]);
    }

    std::cout << f[n];
}


int main() {
    //freopen("main.inp", "r", stdin);
    //freopen("main.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}