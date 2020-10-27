#include <cstdio>
#include <algorithm>
#include <iostream>

#define maxN 501
#define INF 99999999999999999
#define Max 0
#define Min 1

#pragma warning(disable:4996)

typedef long long maxa;
typedef int maxn;

maxn n, mch[maxN];
maxa w[maxN][maxN], ax[maxN], ay[maxN], res;
bool vx[maxN], vy[maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++)
		std::cin >> w[j][i];
}


bool DFS(maxn x) {
	vx[x] = 1;

	for (maxn y = 0; y < n; y++) {
		maxa t = ax[x] + ay[y] - w[x][y];
		if (!vy[y] && t == 0) {
			vy[y] = 1;
			if (mch[y] < 0 || DFS(mch[y]))
				return mch[y] = x, 1;
		}
	}
	return 0;
}


void KM() {
	std::fill(mch, mch + n, -1);

	for (maxn i = 0; i < n; i++)
		for (maxn j = 0; j < n; j++)
			ax[i] = std::max(ax[i], w[i][j]);

	for (maxn i = 0; i < n; i++) {
		while (!DFS(i)) {
			maxa d = INF;
			for (maxn j = 0; j < n; j++) 
				if (!vy[j]) for (maxn k = 0; k < n; k++) 
					if (vx[k]) d = std::min(d, ax[k] + ay[j] - w[k][j]);

			for (maxn j = 0; j < n; j++) if (vx[j]) ax[j] -= d, vx[j] = 0;
			for (maxn j = 0; j < n; j++) if (vy[j]) ay[j] += d, vy[j] = 0;
		}
	}
}


void Process(bool opt) {
	if (opt == Min) {
		for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) w[i][j] = -w[i][j];
	}
	KM();
	res = 0;
	for (maxn i = 0; i < n; i++) res += ax[i] + ay[i];

	if (opt == Min) res = -res;
	std::cout << res << '\n';

	for (maxn i = 0; i < n; i++) std::cout << mch[i] + 1 << ' ';
	std::cout << '\n';
}


int main() {
	//freopen("coupmax.inp", "r", stdin);
	//freopen("coupmax.out", "w", stdout);

	Prepare();
	Process(Max);
	//Process(Min);
}
