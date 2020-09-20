#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>

#define maxN 104
#define X first
#define Y second
#define v(a, b) co_t(b.X - a.X, b.Y - a.Y)
//#define add(a, b) co_t(a.X + b.X, a.Y + b.Y)
//#define dec(a, b) co_t(a.X - b.X, a.Y - b.Y)
#define mul(a, b) (a.X * b.Y - a.Y * b.X)
#define div(a, b) (a.X * b.X + a.Y * b.Y)

typedef int maxn; 
typedef double maxa;
typedef std::pair <maxa, maxa> co_t;

const maxa pi = 2 * acos(0.0);

maxn n;
co_t a[maxN];
maxa angle[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i].X >> a[i].Y;
	a[n + 1] = a[1], a[0] = a[n];
}


maxa S(co_t poly[], maxn n) {
	maxa re = 0;
	for (maxn i = 1; i <= n; i++) re += mul(a[i], a[i + 1]);
	return abs(re) / (maxa)2;
}


maxa P(co_t poly[], maxn n) {
	maxa re = 0;
	for (maxn i = 1; i <= n; i++) {
		re += sqrt((a[i].X - a[i + 1].X) * (a[i].X - a[i + 1].X) + (a[i].Y - a[i + 1].Y) * (a[i].Y - a[i + 1].Y));
	}
	return re;
}


maxa vecAngle(co_t a, co_t b) {
	maxa lenA = sqrt(div(a, a)), lenB = sqrt(div(b, b));
	return acos((div(a, b)) / lenA / lenB);
}


void polyAngle(co_t poly[], maxn n, maxa angle[]) {
	maxa s = 0;
	for (maxn i = 1; i <= n; i++) {
		co_t a = v(poly[i - 1], poly[i]), b = v(poly[i], poly[i + 1]);
		angle[i] = (mul(a, b) > 0 ? vecAngle(a, b) : -vecAngle(a, b));
		s += angle[i];
	}
	for (maxn i = 1; i <= n; i++) 
		angle[i] = s > 0 ? pi - angle[i] : pi + angle[i];
}


void Process() {
	std::cout << round(S(a, n)) << '\n' << round(P(a, n)) << '\n';
	polyAngle(a, n, angle);
	for (maxn i = 1; i <= n; i++) std::cout << round((angle[i] * 180 / pi)) << '\n';
}


int main() {
	//freopen("kvlhp.inp", "r", stdin);
	//freopen("kvlhp.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}