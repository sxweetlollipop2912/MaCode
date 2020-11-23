// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 500001
#define V first
#define cost second
#define has_in(u) (fin[u] != 0 || isK[u])
#define has_out(u) (fout[u] != 0)

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t;

maxn n, K, par[maxN];
maxa fin[maxN], fout[maxN], mx1[maxN], mx2[maxN], mxout[maxN];
bool isK[maxN];
std::vector <ad_t> ad[maxN];


void Prepare() {
    std::cin >> n >> K;

    for(maxn i = 1; i < n; i++) {
        maxn u, v; maxa c;
        std::cin >> u >> v >> c; --u, --v;
        ad[u].push_back(ad_t(v, c));
        ad[v].push_back(ad_t(u, c));
    }

    for(maxn i = 0, u; i < K; i++) std::cin >> u, --u, isK[u] = 1;
}


void DFS_IN(const maxn u) { /// fin, mx1, mx2
    fin[u] = 0;
    mx1[u] = mx2[u] = isK[u]? 0 : -1;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i].V; maxa c = ad[u][i].cost;
        if (par[v] != -1) continue;

        par[v] = u; DFS_IN(v);
        if (!has_in(v)) continue;

        fin[u] += fin[v] + 2 * c;
        if (mx1[v] + c >= mx1[u])
            mx2[u] = mx1[u], mx1[u] = mx1[v] + c;
        else
        if (mx1[v] + c > mx2[u])
            mx2[u] = mx1[v] + c;
        else
        if (mx2[v] != -1 && mx2[v] + c > mx2[u])
            mx2[u] = mx2[v] + c;
    }
    //std::cout << "fin " << u + 1 << ' ' << fin[u] << ' ' << mx1[u] << ' ' << mx2[u] << '\n';
}


void DFS_OUT(const maxn u,  const maxa c_par = 0) { /// fout, mxout
    fout[u] = 0, mxout[u] = -1;
    if (par[u] != u) {
        maxn v = par[u];
        fout[u] = (fout[v] + fin[v] - (fin[u] + has_in(u)*2*c_par)) + 2*c_par;

        if (mxout[v] != -1)
            mxout[u] = mxout[v] + c_par;
        if (mx1[v] != -1 && (mx1[u] == -1 || mx1[v] != mx1[u] + c_par))
            mxout[u] = std::max(mxout[u], mx1[v] + c_par);
        else
        if (mx2[v] != -1)
            mxout[u] = std::max(mxout[u], mx2[v] + c_par);
    }
    if (mxout[u] == -1) fout[u] = 0;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i].V; maxa c = ad[u][i].cost;
        if (par[u] == v) continue;
        DFS_OUT(v, c);
    }

    //std::cout << "fout " << u + 1 << ' ' << fout[u] << ' ' << mxout[u] << ' ' << c_par << '\n';
}


void Process() {
    std::fill(par, par + n, -1);
    par[0] = 0;
    DFS_IN(0);
    DFS_OUT(0);

    for(maxn i = 0; i < n; i++) {
        maxa res = fin[i] + fout[i] - std::max(mx1[i], std::max(mxout[i], (maxa)0));
        std::cout << res << '\n';
    }
}


int main() {
    freopen("cuutro.inp", "r", stdin);
    freopen("cuutro.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
