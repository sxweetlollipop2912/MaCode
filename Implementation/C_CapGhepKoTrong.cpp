#include <iostream> 
#include <cstdio>
#include <algorithm>

#define maxN 501
#define INF 999999999999999999

typedef int maxn;
typedef long long maxa;

maxa w[maxN][maxN], MIN, MAX;
maxn mch[maxN], n;
bool g[maxN][maxN], seen[maxN];


void Prepare() {
	std::cin >> n;

	MIN = INF, MAX = -INF;
	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++)
		std::cin >> w[j][i], MIN = std::min(MIN, w[j][i]), MAX = std::max(MAX, w[j][i]);
}


bool DFS(maxn u) {
	for (maxn v = 0; v < n; v++) 
		if (g[u][v] && !seen[v]) {
			seen[v] = 1;

			if (mch[v] < 0 || DFS(mch[v])) 
				return mch[v] = u, 1;
		}

	return 0;
}


maxn maxBPM() {
	std::fill(mch, mch + n, -1);

	maxn res = 0;
	for (maxn u = 0; u < n; u++) {
		std::fill(seen, seen + n, 0);
		if (DFS(u)) ++res;
	}
	return res;
}


void Init(const maxa x) {
	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) 
		g[i][j] = w[i][j] <= x;
}


void Process() {
	while (MIN != MAX) {
		maxa MID = (MIN + MAX) / 2;
		Init(MID);
		if (maxBPM() == n) MAX = MID;
		else MIN = MID + 1;
	}

	Init(MIN); maxBPM();
	std::cout << MIN << '\n';
	for (maxn i = 0; i < n; i++) std::cout << mch[i] + 1 << ' ';
}


int main() {
	//freopen("COUPEARL.inp", "r", stdin);
	//freopen("COUPEARL.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}