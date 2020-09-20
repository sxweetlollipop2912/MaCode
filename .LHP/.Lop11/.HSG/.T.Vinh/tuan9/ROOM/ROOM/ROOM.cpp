#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define maxN 1001
#define maxA 1000000001

typedef int maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxn> e_t;

maxn n;
maxm F, UF;
maxa d[maxN][maxN], mn[maxN], mx[maxN];
bool fr[maxN][maxN];
std::vector <e_t> e;


void Prepare() {
	std::cin >> n >> F >> UF;

	for (maxm i = 0; i < F; i++) {
		maxn x, y; std::cin >> x >> y, --x, --y;
		std::cin >> d[x][y]; fr[x][y] = fr[y][x] = 1;
		e.push_back(e_t(std::min(x, y), std::max(x, y)));
	}
	for (maxm i = 0; i < UF; i++) {
		maxn x, y; std::cin >> x >> y, --x, --y;
		std::cin >> d[x][y];
		e.push_back(e_t(std::min(x, y), std::max(x, y)));
	}
	std::sort(e.begin(), e.end());
	
	std::fill(mn, mn + n, 0);
	std::fill(mx, mx + n, maxA);
}


bool Process() {
	mn[0] = mx[0] = 0;

	for (maxm i = 0; i < e.size(); i++) {
		maxn u = e[i].first, v = e[i].second;

		if (fr[u][v]) {
			mn[u] = std::max(mn[u], mn[v] - d[u][v]);
			mx[v] = std::min(mx[u] + d[u][v], mx[v]);
		}
		else {
			mn[v] = std::max(mn[u] + d[u][v], mn[v]);
			mx[u] = std::min(mx[v] - d[u][v], mx[u]);
		}

		for (maxn j = v - 1; j >= 0; j--) mn[j] = std::min(mn[j], mn[j + 1]), mx[j] = std::min(mx[j], mx[j + 1]);
	}

	for (maxn i = 0; i < n; i++) if (mx[i] < mn[i]) return 0;
	if (mx[n - 1] == maxA) std::cout << "-2";
	else std::cout << mx[n - 1];  
	return 1;
}


int main() {
	//freopen("room.inp", "r", stdin);
	//freopen("room.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "-1";
}