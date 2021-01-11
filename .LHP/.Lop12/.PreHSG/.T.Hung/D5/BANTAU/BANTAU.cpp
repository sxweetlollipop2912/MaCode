#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 602
#define maxA 10001
#define maxR 60001
#define en first
#define st second

typedef int maxn;
typedef long maxa;
typedef std::pair <maxa, maxa> p_t;

maxn n;
p_t a[maxN];
maxa d[maxN], f[maxN], mnen[maxA], res;
std::vector <maxa> V;


void Prepare() {
    std::cin >> n;
    std::fill(mnen, mnen + maxA, maxA);

    for(maxn i = 0; i < n; i++) {
        std::cin >> a[i].st >> a[i].en >> d[i];
        V.push_back(a[i].st);
        V.push_back(a[i].en);
        mnen[a[i].st] = std::min(mnen[a[i].st], a[i].en);
    }

    V.push_back(0);
    std::sort(V.begin(), V.end());
    V.resize(std::unique(V.begin(), V.end()) - V.begin());
}


void Process() {
    std::fill(f, f + maxN, maxR);
    f[0] = 0;

    for(maxn i = 1; i < V.size(); i++) {
        maxa mnj = maxA;
        for(maxn j = i; j < V.size() && V[j] < mnj; j++) {
            if (i != j) mnj = std::min(mnj, mnen[V[j]]);
            maxa mxd = 0;
            for(maxn ai = 0; ai < n; ai++)
                if (a[ai].st <= V[i] && a[ai].en >= V[i] && a[ai].en <= V[j])
                    mxd = std::max(mxd, d[ai]);
            f[j] = std::min(f[j], f[i - 1] + mxd);
        }
    }

    std::cout << f[V.size() - 1];
}


int main() {
    freopen("bantau.inp", "r", stdin);
    freopen("bantau.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
