#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100002
#define lit second
#define cost first
#define INF 99999999999999999

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> f_t;

maxn milk, fact, peas;
maxa m[maxN], p[maxN], ff[maxN], fp[maxN], res;
f_t f[maxN];


void Prepare() {
	std::cin >> milk >> fact >> peas;
	for (maxn i = 0; i < milk; i++) std::cin >> m[i];
	for (maxn i = 0; i < fact; i++) std::cin >> f[i].lit >> f[i].cost;
	for (maxn i = 0; i < peas; i++) std::cin >> p[i];

	std::sort(m, m + milk);
	f[fact].lit = INF, f[fact].cost = 0;
	std::sort(f, f + fact + 1);
	std::sort(p, p + peas);
}


void Factory() {
	maxn fi = fact;
	ff[0] = 0;
	for (maxn mi = milk - 1; mi >= 0; mi--) {
		ff[milk - mi] = ff[milk - mi - 1];
		while (m[mi]) {
			if (!f[fi].lit) --fi;
			maxa sell = std::min(m[mi], f[fi].lit);
			ff[milk - mi] += sell * f[fi].cost;
			m[mi] -= sell, f[fi].lit -= sell;
		}
	}
}


void Peasant() {
	fp[0] = 0;
	for (maxn i = 1; i <= peas; i++) {
		fp[i] = fp[i - 1] + p[peas - i];
	}
}


void Process() {
	Peasant();
	Factory();

	res = 0;
	for (maxn i = 0; i <= milk; i++) {
		res = std::max(res, fp[std::min(peas, i)] + ff[std::min(fact, milk - i)]);
	}
	std::cout << res;
}


int main() {
	//freopen("milk.inp", "r", stdin);
	//freopen("milk.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}