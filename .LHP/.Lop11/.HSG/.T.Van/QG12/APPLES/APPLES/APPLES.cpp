#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>

#define maxN 1000001
#define X first
#define Y second
#define d(a, b) ((a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y))

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> p_t;

maxn n, id[maxN], st;
p_t co[maxN];
double ang[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> co[i].X >> co[i].Y, st = co[st].Y > co[i].Y ? i : st, id[i] = i;
}


bool cmp(const maxn x, const maxn y) {
	return ang[x] < ang[y];
}


void Process() {
	p_t v0; v0.X = -1, v0.Y = 0; maxa d0 = 1;

	for (maxn i = 0; i < n; i++) {
		if (i == st) continue;
		p_t v; v.X = co[i].X - co[st].X, v.Y = co[i].Y - co[st].Y; maxa dv = d(co[i], co[st]);
		ang[i] = (v0.X * v.X + v0.Y * v.Y) / (double)sqrt(d0 * dv);
	}
	ang[st] = -2;

	std::sort(id, id + n, cmp);
	std::cout << st + 1 << ' ' << id[(n - 2) / 2 + 1] + 1;
}


int main() {
	//freopen("apples.inp", "r", stdin);
	//freopen("apples.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}