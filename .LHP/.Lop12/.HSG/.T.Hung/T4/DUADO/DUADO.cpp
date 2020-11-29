#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

#define maxN 300003

typedef long maxn;
typedef long long maxa;

maxn n, N;
maxa M, mnen[maxN], res;
std::map <maxa, maxa> men;
std::vector <maxa> Vst;


void Prepare() {
    std::cin >> n >> M;

    for(maxn i = 0; i < n; i++) {
        maxa st, en; std::cin >> st >> en;
        if (st <= en) continue;

        if (men.find(st) == men.end()) men[st] = en;
        else men[st] = std::min(men[st], en);
        Vst.push_back(st);
    }

    std::sort(Vst.begin(), Vst.end());
    Vst.resize(std::unique(Vst.begin(), Vst.end()) - Vst.begin());
    N = Vst.size();
}


maxa Process() {
    if (N == 0) return M;

    mnen[n] = M;
    for(maxn i = n - 1; i >= 0; i--) mnen[i] = std::min(mnen[i + 1], men[Vst[i]]);

    maxa mn = -mnen[0] * 2, f;
    for(maxn i = 0; i < N; i++) {
        f = Vst[i] * 2 + mn;
        if (i > mnen[i + 1]) continue;
        mn = std::min(mn, f - mnen[i + 1] * 2);
    }
    res = M + f;
    return res;
}


int main() {
    //freopen("duado.inp", "r", stdin);
    //freopen("duado.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    std::cout << Process();
}