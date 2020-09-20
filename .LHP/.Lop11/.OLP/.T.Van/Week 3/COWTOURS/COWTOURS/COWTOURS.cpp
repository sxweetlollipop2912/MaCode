#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <math.h>
#include <iomanip>

#define maxN 151
#define maxR (maxa)9999999999999999
#define X first
#define Y second
#define d(x, y) sqrt((x.X - y.X) * (x.X - y.X) + (x.Y - y.Y) * (x.Y - y.Y))

typedef int maxn;
typedef long double maxa;
typedef std::pair <maxa, maxa> co_t;

const maxa eps = 1e-6;

maxn n;
co_t p[maxN];
maxa ad[maxN][maxN], mx[maxN], res;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> p[i].X >> p[i].Y;

	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) {
		char c; std::cin >> c;
		if (i != j) ad[i][j] = c == '0' ? maxR : d(p[i], p[j]);
	}
}


void Process() {
	for (maxn k = 0; k < n; k++) for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++)
		ad[i][j] = std::min(ad[i][j], ad[i][k] + ad[k][j]);

	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) if (ad[i][j] != maxR) 
		mx[i] = std::max(mx[i], ad[i][j]);

	res = maxR;
	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) if (ad[i][j] == maxR) res = std::min(res, mx[i] + mx[j] + d(p[i], p[j]));

	std::cout << std::fixed; std::cout << std::setprecision(6);
	std::cout << res;
}


int main() {
	//freopen("cowtours.inp", "r", stdin);
	//freopen("cowtours.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}