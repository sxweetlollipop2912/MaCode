#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <iomanip>

#define maxN 121
#define maxA 401
#define X first
#define Y second
#define maxT (maxt)10000000001

typedef int maxn, maxa;
typedef long double maxt;
typedef std::pair <maxa, maxa> co_t;

maxn n, N, x[maxN], y[maxN];
co_t p[maxN], resc;
maxt t[maxN][maxN], T[maxN][maxN], res;
std::map <co_t, maxn> mp;


maxn Idx(const co_t &co) {
	if (mp.find(co) == mp.end()) mp[co] = N, p[N] = co, ++N;
	return mp[co];
}


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < 3 * n; i++) for (maxn j = i + 1; j < 3 * n; j++) t[i][j] = t[j][i] = maxT;

	for (maxn i = 0; i < n; i++) {
		co_t c1, c2, c3;
		std::cin >> c1.X >> c1.Y >> c3.X >> c3.Y;
		c1.X *= 2, c1.Y *= 2, c3.X *= 2, c3.Y *= 2, c2.X = (c1.X + c3.X) / 2, c2.Y = (c1.Y + c3.Y) / 2;

		maxn idx1 = Idx(c1), idx2 = Idx(c2), idx3 = Idx(c3);
		std::cin >> t[idx1][idx3], T[idx1][idx3] = t[idx3][idx1] = T[idx3][idx1] = t[idx1][idx3];
		t[idx1][idx2] = T[idx1][idx2] = t[idx2][idx1] = T[idx2][idx1] = t[idx1][idx3] / 2;
		t[idx2][idx3] = T[idx2][idx3] = t[idx3][idx2] = T[idx3][idx2] = t[idx1][idx3] / 2;

		x[2 * i] = idx1, y[2 * i] = idx2, x[2 * i + 1] = idx2, y[2 * i + 1] = idx3;
	}
}


maxt Cal(maxt t1, maxt t2, maxt t) {
	if (t1 > t2) std::swap(t1, t2);

	if (t1 + t > t2) return t2 + (t - (t2 - t1)) / 2;
	return t1 + t;
}


void Process() {
	for (maxn k = 0; k < N; k++) for (maxn i = 0; i < N; i++) for (maxn j = 0; j < N; j++)
		t[i][j] = std::min(t[i][j], t[i][k] + t[k][j]);

	res = maxT;
	for (maxn i = 0; i < N; i++) {
		if ((p[i].X % 2) || (p[i].Y % 2)) continue;
		maxt re = 0;
		for (maxn j = 0; j < 2 * n; j++) {
			re = std::max(re, Cal(t[i][x[j]], t[i][y[j]], T[x[j]][y[j]]));
		}
		if (res <= re) continue;
		resc = p[i], res = re;
	}

	std::cout << resc.X / 2 << ' ' << resc.Y / 2 << '\n';
	std::cout << std::fixed; std::cout << std::setprecision(2);
	std::cout << res;
}


int main() {
	//freopen("quediem.inp", "r", stdin);
	//freopen("quediem.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}