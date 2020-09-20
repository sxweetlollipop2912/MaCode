#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <iomanip>

#define maxN 101
#define x first
#define y second
#define d(a, b) ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y))
#define d2(a, b) sqrt(d(a, b))
#define sqr(x) ((x) * (x))
#define idx(x) ((x) % n)
#define eps (maxa)0.01
#define dif(a, b) (abs((a) - (b)) > eps)

typedef int maxn;
typedef long double maxa;
typedef std::pair <maxa, maxa> co_t;

maxn n;
co_t a[maxN], b[maxN];
maxa res;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i].x >> a[i].y;
	for (maxn i = 0; i < n; i++) std::cin >> b[i].x >> b[i].y;
}


maxa Cos(const co_t a, const co_t O, const co_t b) {
	co_t vOa, vOb; 
	vOa.x = a.x - O.x, vOa.y = a.y - O.y;
	vOb.x = b.x - O.x, vOb.y = b.y - O.y;

	return (vOa.x * vOb.x + vOa.y * vOb.y) / (d2(O, a) * d2(O, b));
}


void Process() {
	std::cout << std::fixed;
	std::cout << std::setprecision(3);

	for (maxn iib = 0, ia, ib; iib < n; iib++) {
		maxa k = d2(a[0], a[1]) / d2(b[iib], b[idx(iib + 1)]);
		for (ia = 0, ib = iib; ia < n; ia++, ib = idx(ib + 1)) {

			//std::cout << d2(a[ia], a[idx(ia + 1)]) * d2(b[idx(ib + 1)], b[idx(ib + 2)]) << ' ' << d2(a[idx(ia + 1)], a[idx(ia + 2)]) * d2(b[ib], b[idx(ib + 1)]) << '\n';
			//std::cout << Cos(a[ia], a[idx(ia + 1)], a[idx(ia + 2)]) << ' ' << Cos(b[ib], b[idx(ib + 1)], b[idx(ib + 2)]) << '\n';

			if (dif(d2(a[ia], a[idx(ia + 1)]) / d2(b[ib], b[idx(ib + 1)]), d2(a[idx(ia + 1)], a[idx(ia + 2)]) / d2(b[idx(ib + 1)], b[idx(ib + 2)]))) break;
			if (dif(Cos(a[ia], a[idx(ia + 1)], a[idx(ia + 2)]), Cos(b[ib], b[idx(ib + 1)], b[idx(ib + 2)]))) break;
		}
		//std::cout << k << ' ' << ia << '\n';
		if (ia != n) continue;
		std::cout << k; return;
	}
}


int main() {
	//freopen("dgdd.inp", "r", stdin);
	//freopen("dgdd.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}