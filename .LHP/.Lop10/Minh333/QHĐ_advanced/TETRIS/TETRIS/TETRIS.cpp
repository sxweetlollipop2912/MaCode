#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>

#pragma warning(disable:4996)

#define maxN 203
//#define maxA 5
//#define maxR 976562500001 // 250^5

typedef long long maxn, maxa;

struct info {
	maxn cnt;
	maxa col;
};
info newInfo(maxn cnt, maxa col) {
	info re;
	re.cnt = cnt; re.col = col;
	return re;
}

maxn N, n, left[maxN][maxN];
maxa f[maxN][maxN];
std::vector <info> a;


void Prepare() {
	std::cin >> N;

	maxn cnt;
	maxa col;
	char cc;
	std::cin >> cc;
	col = cc - '0' + 1;

	cnt = 1;
	for (maxn i = 1; i < N; i++) {
		maxa c;
		std::cin >> cc;
		c = cc - '0' + 1;

		if (c == col) cnt++;
		else {
			a.push_back(newInfo(cnt, col));
			cnt = 1;
			col = c;
		}
	}

	a.push_back(newInfo(cnt, col));
	n = a.size();
}


maxa pow(maxa cnt) {
	return cnt * cnt;
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		std::fill(f[i], f[i] + n, 0);
		std::fill(left[i], left[i] + n, 0);
	}


	for (maxn r = 0; r < n; r++) {
		f[r][r] = pow(a[r].cnt);
		left[r][r] = a[r].cnt;

		for (maxn m = r - 1; m >= 0; m--) { 
			for (maxn l = m; l >= 0; l--) { // r > 0

				maxa re_tmp = f[l][m] + f[m + 1][r];
				maxn left_tmp = left[r][r];

				if (a[m].col == a[r].col) {
					re_tmp = f[l][m] - pow(left[l][m]) + pow(left[l][m] + a[r].cnt) + f[m + 1][r - 1]; // m + 1 <= r
					left_tmp = left[l][m] + left[r][r];
				}

				if (f[l][r] >= re_tmp) continue; // f[l][r] > 0

				f[l][r] = re_tmp;
				left[l][r] = left_tmp;
			}
		}
	}

	std::cout << f[0][n - 1];
}


int main() {
	//freopen("tetris.inp", "r", stdin);
	//freopen("tetris.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}