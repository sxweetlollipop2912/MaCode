#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iomanip>

#define maxN 1001
//#define maxA 1001
#define x first
#define y second
#define mul(a, b) (a.x * b.y - a.y * b.x)
#define vAB(a, b) co_t(b.x - a.x, b.y - a.y)

typedef int maxn, maxa;
typedef double maxs;
typedef std::pair <maxa, maxa> co_t;

maxn n, res;
co_t tg[3], p[maxN];


void Prepare() {
	std::cin >> tg[0].x >> tg[0].y >> tg[1].x >> tg[1].y >> tg[2].x >> tg[2].y >> n;
	for (maxn i = 0; i < n; i++) std::cin >> p[i].x >> p[i].y;
}


maxs S(const maxs ax, const maxs ay, const maxs bx, const maxs by, const maxs cx, const maxs cy) {
	return abs(ax * by - ay * bx + bx * cy - by * cx + cx * ay - cy * ax) / (maxs)2;
}


void Process() {
	std::cout << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << S(tg[0].x, tg[0].y, tg[1].x, tg[1].y, tg[2].x, tg[2].y) << '\n';

	res = 0;
	for (maxn i = 0; i < n; i++) {
		if (mul(vAB(tg[0], p[i]), vAB(p[i], tg[1])) >= 0 && mul(vAB(tg[1], p[i]), vAB(p[i], tg[2])) >= 0 && mul(vAB(tg[2], p[i]), vAB(p[i], tg[0])) >= 0) ++res;
		if (mul(vAB(tg[0], p[i]), vAB(p[i], tg[1])) <= 0 && mul(vAB(tg[1], p[i]), vAB(p[i], tg[2])) <= 0 && mul(vAB(tg[2], p[i]), vAB(p[i], tg[0])) <= 0) ++res;
	}
	std::cout << res;
}


int main() {
	//freopen("point.inp", "r", stdin);
	//freopen("point.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}