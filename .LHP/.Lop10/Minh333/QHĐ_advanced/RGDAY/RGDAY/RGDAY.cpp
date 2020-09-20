#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 203
#define maxA 201
#define maxR 1600000001 // 200^3 * 200
#define DEBUG 0

typedef int maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], f[maxN][maxN], trace[maxN][maxN];
std::vector <maxn> res;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i];
	}
}


void Process() {
	for (maxn i = 1; i < n - 1; i++)
		for (maxn j = i; j < n - 1; j++)
			f[i][j] = maxR;


	for (maxn len = 1; len <= n - 2; len++)
		for (maxn x = 1; x < n - 1; x++) {

			maxn L = std::max(0, x - len);
			maxn R = std::min(n - 1, x + len);

			if (x + len == R)
				for (maxn l = L; l < x; l++) {
					maxa tmp = a[l] * a[x] * a[R] + f[l + 1][x - 1] + f[x + 1][R - 1];
					if (f[l + 1][R - 1] <= tmp) continue;

					f[l + 1][R - 1] = tmp;
					trace[l + 1][R - 1] = x;
				}

			if (x - len == L)
				for (maxn r = x + 1; r <= R; r++) {
					maxa tmp = a[L] * a[x] * a[r] + f[L + 1][x - 1] + f[x + 1][r - 1];
					if (f[L + 1][r - 1] <= tmp) continue;

					f[L + 1][r - 1] = tmp;
					trace[L + 1][r - 1] = x;
				}
		}
}


void Trace(maxn l, maxn r) {
	if (l > r) return;
	res.push_back(trace[l][r]);

	Trace(l, trace[l][r] - 1);
	Trace(trace[l][r] + 1, r);
}


int main() {
	//freopen("rgday.inp", "r", stdin);
	//freopen("rgday.out","w",stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
	Trace(1, n - 2);

	if (DEBUG) {
		for (maxn i = 0; i < n; i++)
			for (maxn j = 0; j < n; j++) std::cout << trace[i][j] + 1 << " \n"[j == n - 1];
	}

	std::cout << f[1][n - 2] << '\n';
	for (maxn i = res.size() - 1; i >= 0; i--) std::cout << res[i] + 1 << ' ';
}
