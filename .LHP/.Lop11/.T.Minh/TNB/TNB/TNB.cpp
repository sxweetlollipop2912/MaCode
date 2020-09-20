#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>

#define maxN 102
#define X first
#define Y second

typedef int maxn;
typedef double maxa;
typedef std::pair <maxa, maxa> p_t;

const maxa PI = acos(-1.0);
const maxa EPS = 1e-9;

maxn n;
p_t p[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> p[i].X >> p[i].Y;
	p[n] = p[0];
}

p_t toVec(p_t a, p_t b) { return p_t(b.X - a.X, b.Y - a.Y); }

maxa norm_sq(p_t v) { return v.X * v.X + v.Y * v.Y; }

maxa dot(p_t a, p_t b) { return (a.X * b.X + a.Y * b.Y); }

maxa angle(p_t a, p_t o, p_t b) { p_t oa = toVec(o, a), ob = toVec(o, b); return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

maxa cross(p_t a, p_t b) { return a.X * b.Y - a.Y * b.X; }

bool ccw(p_t p, p_t q, p_t r) { return cross(toVec(p, q), toVec(p, r)) > 0; }

bool inPolygon(p_t pt, p_t p[]) {
	maxa sum = 0; 
	for (maxn i = 0; i < n; i++) { 
		if (ccw(pt, p[i], p[i + 1])) sum += angle(p[i], pt, p[i + 1]); 
		else sum -= angle(p[i], pt, p[i + 1]);
	}
	return fabs(fabs(sum) - 2*PI) < EPS; 
}

maxa inLine(p_t a, p_t b, p_t o) {
	p_t oa = toVec(o, a), ob = toVec(o, b);
	return fabs(oa.X * ob.Y - oa.Y * ob.X) < EPS;
}


int Result(p_t P) {
	if (!inPolygon(P, p)) return -1;
	for (maxn i = 0; i < n; i++) if (inLine(p[i], p[i + 1], P)) return 0;
	return 1;
}


void Process() {
	maxn m; std::cin >> m;
	
	while (m--) {
		p_t P; std::cin >> P.X >> P.Y;
		std::cout << Result(P) << ' ';
	}
}


int main() {
	//freopen("tnb.inp", "r", stdin);
	//freopen("tnb.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}