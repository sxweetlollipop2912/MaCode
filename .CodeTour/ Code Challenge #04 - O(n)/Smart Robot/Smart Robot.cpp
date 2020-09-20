#include <iostream>
#include <algorithm>

#define maxN 102

typedef int maxn, maxa;
typedef long maxm;

maxn n, mch[maxN], res;
maxa c[maxN], a[maxN];
bool done[maxN], g[maxN][maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 1; i <= n; i++) {
		std::cin >> a[i] >> c[i];
	}
	for (maxn i = 1; i <= n; i++) for (maxn j = i + 1; j <= n; j++) {
		if (a[i] != c[i] && a[i] + a[j] == c[i] + c[j]) g[i][j] = g[j][i] = 1;// , std::cout << i << ' ' << j << '\n';
	}
}


bool DFS(const maxn u) {
	if (done[u]) return 0;
	done[u] = 1;
	for (maxn v = 1; v <= n; v++) {
		if (g[u][v] && (!mch[v] || DFS(mch[v]))) {
			mch[v] = u;
			return 1;
		}
	}
	return 0;
}


void Process() {
	for (maxn i = 1; i <= n; i++) {
		std::fill(done, done + n + 1, 0);
		res += DFS(i);
		//std::cout << i << ' ' << res << '\n';
	}
	std::cout << res / 2;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}