#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 1000001
#define maxC 27
#define C 26
#define num(c) ((c) - 'a')

typedef long maxn;
typedef int maxa;

maxn n;
int opt[maxN];
maxa x[maxN], y[maxN], par[maxC];
std::vector <maxa> res;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		char cx, cy;
		std::cin >> opt[i] >> cx, x[i] = num(cx);
		if (opt[i] == 2) std::cin >> cy, y[i] = num(cy);
	}

	for (maxa i = 0; i < C; i++) par[i] = i;
}


void Process() {
	for (maxn i = n - 1; i >= 0; i--) {
		if (opt[i] == 1) res.push_back(par[x[i]]);
		else par[x[i]] = par[y[i]];
	}
	for (maxn i = (maxn)res.size() - 1; i >= 0; i--) std::cout << (char)(res[i] + 'a');
}


int main() {
	//freopen("paint.inp", "r", stdin);
	//freopen("paint.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}