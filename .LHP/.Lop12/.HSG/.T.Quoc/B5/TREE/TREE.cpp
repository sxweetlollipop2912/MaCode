#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 100001

typedef long maxn;
typedef long long maxa;

const maxa MOD = 1e9 + 7;

maxn n, par[maxN], mx[maxN][3];
maxa cnt[maxN][3];
std::vector <maxn> ad[maxN];


void Prepare() {
    std::cin >> n;

    for(maxn i = 1; i < n; i++) {
        maxn u, v; std::cin >> u >> v; --u; --v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
}


void DFS(const maxn u) {
    cnt[u][0] = 1, mx[u][0] = 0;
    cnt[u][1] = 1, mx[u][1] = 1;
    cnt[u][2] = 1, mx[u][2] = 1;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[u] == v) continue;

        par[v] = u; DFS(v);
        mx[u][0] += mx[v][2]; cnt[u][0] = (cnt[u][0] * cnt[v][2]) % MOD;

        if (mx[v][1] - 1 > mx[v][0]) {
            mx[u][1] += mx[v][1] - 1; 
            cnt[u][1] = (cnt[u][1] * cnt[v][1]) % MOD;
        }
        else 
        if (mx[v][0] > mx[v][1] - 1) {
            mx[u][1] += mx[v][0]; 
            cnt[u][1] = (cnt[u][1] * cnt[v][0]) % MOD;
        }
        else {
            mx[u][1] += mx[v][0]; 
            cnt[u][1] = (cnt[u][1] * (cnt[v][0] + cnt[v][1])) % MOD;
        }
    }

    if (mx[u][0] > mx[u][1]) mx[u][2] = mx[u][0], cnt[u][2] = cnt[u][0];
    else
    if (mx[u][1] > mx[u][0]) mx[u][2] = mx[u][1], cnt[u][2] = cnt[u][1];
    else 
    mx[u][2] = mx[u][0], cnt[u][2] = (cnt[u][0] + cnt[u][1]) % MOD;

    /*std::cout << u + 1 << '\n';
    std::cout << "mx " << mx[u][0] << ' ' << mx[u][1] << ' ' << mx[u][2] << '\n';
    std::cout << "cnt " << cnt[u][0] << ' ' << cnt[u][1] << ' ' << cnt[u][2] << '\n';*/
}


void Process() {
    std::fill(par, par + n, -1); par[0] = 0;
    DFS(0);
    std::cout << mx[0][2] << '\n' << cnt[0][2];
}


int main() {
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}