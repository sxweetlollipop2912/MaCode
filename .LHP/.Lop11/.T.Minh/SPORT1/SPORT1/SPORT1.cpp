#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <string>

#define maxN 501
#define unq -1
#define INF 50001
#define N std::max(m, n)

typedef int maxn, maxa;
typedef std::string str;

maxn n, m, mch[maxN];
maxa w[maxN][maxN], ax[maxN], ay[maxN], res;
bool done_x[maxN], done_y[maxN];


void Prepare() {
	std::cin >> n >> m;

	str s;
	std::getline(std::cin, s);
	//std::cin.ignore();

	for (maxn i = 0; i < n; i++) {
		std::getline(std::cin, s);
		std::stringstream ss;
		ss << s;
		maxn j;
		//std::cout << s << '\n';
		while (ss >> j) w[j - 1][i] = 1;
	}
}


bool DFS(const maxn x) {
	done_x[x] = 1;

	for (maxn y = 0; y < N; y++) {
		maxa t = ax[x] + ay[y] - w[x][y];
		if (done_y[y] || w[x][y] == unq || t != 0) continue;
		done_y[y] = 1;
		if (mch[y] == -1 || DFS(mch[y])) return (mch[y] = x, 1);
	}
	return 0;
}


void Process() {
	std::fill(mch, mch + N, -1);

	for (maxn i = 0; i < N; i++) for (maxn j = 0; j < N; j++)
		ax[i] = std::max(ax[i], w[i][j]);

	for (maxn i = 0; i < N; i++) {
		while (!DFS(i)) {
			maxa d = INF;
			for (maxn j = 0; j < N; j++) {
				if (done_y[j]) continue;
				for (maxn k = 0; k < N; k++) {
					if (done_x[k]) d = std::min(d, ax[k] + ay[j] - w[k][j]);
				}
			}
			for (maxn j = 0; j < N; j++) if (done_x[j]) ax[j] -= d, done_x[j] = 0;
			for (maxn j = 0; j < N; j++) if (done_y[j]) ay[j] += d, done_y[j] = 0;
		}
	}

	res = 0;
	for (maxn i = 0; i < N; i++) res += ax[i] + ay[i];
	std::cout << res << '\n';
	for (maxn i = 0; i < n; i++) if (w[mch[i]][i] == 1) std::cout << i + 1 << ' ' << mch[i] + 1 << '\n';
}


int main() {
	//freopen("sport1.inp", "r", stdin);
	//freopen("sport1.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}