#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>

#define maxN 201
#define X first
#define Y second
#define d(a, b) (maxa)((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y))

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> e_t;
typedef double maxd;

const maxd eps = 10e-7;

maxn mch[maxN], n, m, N;
bool g[maxN][maxN], seen[maxN];
e_t an[maxN], am[maxN];


void Prepare() {
	std::cin >> n >> m;
	N = std::max(n, m);

	for(maxn i = 0; i < n; i++) std::cin >> an[i].X >> an[i].Y;
    for(maxn i = 0; i < m; i++) std::cin >> am[i].X >> am[i].Y;

	for(maxn i = 0; i < n - 1; i++) for(maxn j = 0; j < m; j++) {
		maxd d1 = (maxa)4 * d(an[i], an[i + 1]);
		maxd d2 = (maxd)(d(an[i], am[j]) + d(an[i + 1], am[j])) + (maxd)2 * sqrt(d(an[i], am[j]) * d(an[i + 1], am[j]));

        if (d2 - d1 > eps) continue;
        g[j][i] = 1;
        //std::cout << i << ' ' << j << '\n';
	}
}


bool DFS(maxn u) {
	for (maxn v = 0; v < N; v++)
		if (g[u][v] && !seen[v]) {
			seen[v] = 1;

			if (mch[v] < 0 || DFS(mch[v]))
				return mch[v] = u, 1;
		}

	return 0;
}


maxn maxBPM() {
	std::fill(mch, mch + N, -1);

	maxn res = 0;
	for (maxn u = 0; u < N; u++) {
		std::fill(seen, seen + N, 0);
		if (DFS(u)) ++res;
	}
	return res;
}


void Process() {
	std::cout << (n + maxBPM()) << '\n';

	std::cout << an[0]. X << ' ' << an[0].Y << ' ';
	for (maxn i = 0; i < n - 1; i++) {
        if (mch[i] != -1)
            std::cout << am[mch[i]]. X << ' ' << am[mch[i]].Y << ' ';
        std::cout << an[i + 1]. X << ' ' << an[i + 1].Y << ' ';
	}
}


int main() {
	//freopen("BG.inp", "r", stdin);
	//freopen("BG.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}
