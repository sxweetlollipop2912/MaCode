// AC SPOJ
#include <iostream>
#include <algorithm>

#define maxN 201
#define maxA 40001

typedef int maxn, maxa;

maxn n, mchy[maxN];
maxa w[maxN][maxN], ax[maxN], ay[maxN], res;
bool dx[maxN], dy[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn x = 0; x < n; x++) for (maxn y = 0; y < n; y++) w[x][y] = -maxA;
	for (maxn x, y; std::cin >> x >> y;)
		--x, --y, std::cin >> w[x][y], w[x][y] = -w[x][y];
}


bool DFS(const maxn x) {
	dx[x] = 1;
	for (maxn y = 0; y < n; y++) {
		maxa t = ax[x] + ay[y] - w[x][y];
		if (!dy[y] && !t) {
			dy[y] = 1;
			if (mchy[y] != -1 && !DFS(mchy[y])) continue;
			mchy[y] = x; return 1;
		}
	}
	return 0;
}


void Process() {
	std::fill(mchy, mchy + n, -1);
	for (maxn x = 0; x < n; x++) for (maxn y = 0; y < n; y++) ax[x] = std::max(ax[x], w[x][y]);

	for (maxn x = 0; x < n; x++) {
		while (!DFS(x)) {
			maxa d = maxA;
			for (maxn j = 0; j < n; j++) {
				if (dy[j]) continue;
				for (maxn i = 0; i < n; i++) if (dx[i]) d = std::min(d, ax[i] + ay[j] - w[i][j]);
			}
			for (maxn i = 0; i < n; i++) if (dx[i]) ax[i] -= d, dx[i] = 0;
			for (maxn i = 0; i < n; i++) if (dy[i]) ay[i] += d, dy[i] = 0;
		}
	}

	for (maxn i = 0; i < n; i++) res += ax[i] + ay[i];
	std::cout << -res << '\n';
	for (maxn y = 0; y < n; y++) if (mchy[y] != -1 && w[mchy[y]][y] != -maxA) std::cout << mchy[y] + 1 << ' ' << y + 1 << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}