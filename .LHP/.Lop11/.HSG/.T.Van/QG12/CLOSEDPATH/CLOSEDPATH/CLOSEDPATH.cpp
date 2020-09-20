#include <iostream>
#include <algorithm>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>

#define maxN 100001
#define X first
#define Y second
#define d(a, b) ((a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y))
#define eps 1e-9

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> p_t;

maxn n, st, id[maxN];
p_t co[maxN];
double ang[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> co[i].X >> co[i].Y, st = co[st].Y > co[i].Y ? i : co[st].Y == co[i].Y && co[st].X > co[i].X ? i : st, id[i] = i;
}

p_t toVec(p_t a, p_t b) {
	p_t v; v.X = b.X - a.X, v.Y = b.Y - a.Y;
	return v;
}
double cross(p_t a, p_t b) { return a.X * b.Y - a.Y * b.X; }
bool ccw(p_t p, p_t q, p_t r) { return cross(toVec(p, q), toVec(p, r)) > 0; }
bool collinear(p_t p, p_t q, p_t r) { return fabs(cross(toVec(p, q), toVec(p, r))) < eps; }


bool cmp(const maxn x, const maxn y) {
	if (collinear(co[st], co[x], co[y])) return d(co[st], co[x]) < d(co[st], co[y]);
	return ang[x] > ang[y];
}


void Process() {
	p_t v0; v0.X = 1, v0.Y = 0; maxa d0 = 1;

	for (maxn i = 0; i < n; i++) {
		if (i == st) continue;
		p_t v; v.X = co[i].X - co[st].X, v.Y = co[i].Y - co[st].Y; maxa dv = d(co[i], co[st]);
		ang[i] = (v0.X * v.X + v0.Y * v.Y) / (double)sqrt(d0 * dv);
	}

	std::sort(id, id + n, cmp);
	std::cout << co[st].X << co[st].Y << '\n';
	for (maxn i = 0; i < n; i++) if (id[i] != st) std::cout << co[id[i]].X << ' ' << co[id[i]].Y << '\n';
}


int main() {
	//freopen("closedpath.inp", "r", stdin);
	//freopen("closedpath.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}