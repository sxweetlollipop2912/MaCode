// AC
#include <iostream>
#include <cstdio>
#include <algorithm>
 
#define maxN 200002
#define maxS 800010
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)
#define mid(l, r) (((l) + (r)) / 2)
 
typedef long maxn;
typedef long long maxa;

const maxa INF = 8999999999999999999;
 
maxn n;
maxa M, A, B, sum[maxN], f[maxN], sA[maxS], sB[maxS], res;
 
 
void Prepare() {
    std::cin >> n >> M >> A >> B;
    for(maxn i = 1; i <= n; i++) std::cin >> sum[i], sum[i] += sum[i - 1];
 
    std::fill(sA, sA + maxS, INF);
    std::fill(sB, sB + maxS, INF);
}
 
 
maxa Update(maxa seg[], const maxn IDX, const maxa VAL, const maxn Ls = 0, const maxn Rs = n, const maxn ids = 0) {
    if (Ls > Rs) return INF;
    if (Ls > IDX || Rs < IDX) return seg[ids];
    if (Ls == Rs)
        return (seg[ids] = VAL);

    return (seg[ids] = 
        std::min(Update(seg, IDX, VAL, Ls, mid(Ls, Rs), cle(ids)), Update(seg, IDX, VAL, mid(Ls, Rs) + 1, Rs, cri(ids))));
}
 
 
maxa Min(maxa seg[], const maxn l, const maxn r, const maxn Ls = 0, const maxn Rs = n, const maxn ids = 0) {
    if (Ls > Rs) return INF;
    if (Ls > r || Rs < l) return INF;
    if (Ls >= l && Rs <= r) return seg[ids];
    
    return std::min(Min(seg, l, r, Ls, mid(Ls, Rs), cle(ids)), Min(seg, l, r, mid(Ls, Rs) + 1, Rs, cri(ids)));
}
 
 
void Process() {
    Update(sA, 0, 0);
    Update(sB, 0, 0);
 
    for(maxn i = 1; i <= n; i++) {
        f[i] = INF;
        maxn idx = std::lower_bound(sum, sum + n + 1, sum[i] - M) - sum;
 
        if (idx < i)
            f[i] = -B*sum[i] + B*M + Min(sB, idx, i - 1);
        if (idx > 0)
            f[i] = std::min(f[i], -A*M + A*sum[i] + Min(sA, 0, idx - 1));
 
        Update(sB, i,  B*sum[i] + f[i]);
        Update(sA, i, -A*sum[i] + f[i]);
    }
 
    std::cout << f[n];
}
 
 
int main() {
    freopen("candy.inp", "r", stdin);
    freopen("candy.out", "w", stdout);
 
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
 
    Prepare();
    Process();
}