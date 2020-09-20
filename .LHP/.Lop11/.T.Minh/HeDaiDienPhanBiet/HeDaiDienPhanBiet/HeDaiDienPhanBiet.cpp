#include <iostream> 
#include <cstdio>
#include <algorithm>

#define maxN 502
#define maxA 502
//#define INF 999999999999999999

typedef int maxn;
//typedef long long maxa;

maxn mch[maxN], n, N;
bool g[maxN][maxN], seen[maxN];


void Prepare() {
	std::cin >> n;
	N = n;
	for (maxn i = 0; i < n; i++) {
		maxn size; std::cin >> size;
		maxn a;
		while (size--)
			std::cin >> a, g[a][i] = 1, N = std::max(N, a + 1);
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


bool Process() {
	if (maxBPM() != n) return 0;
	std::cout << "YES\n";
	for (maxn i = 0; i < n; i++) std::cout << mch[i] << ' ';
}


int main() {
	//freopen("COUPEARL.inp", "r", stdin);
	//freopen("COUPEARL.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "NO";
}