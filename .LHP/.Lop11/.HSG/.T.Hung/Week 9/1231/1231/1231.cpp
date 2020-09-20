// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#pragma warning(disable:4996)

#define maxN 4002002
#define maxT 2003
#define maxH 2002

typedef long maxn, maxh;
typedef long long maxa;

maxn n, N, id[maxT][maxH];
maxh H, F;
maxa c[maxN], mx[maxN], mxh[maxH];


void Init() {
	std::fill(c, c + maxN, 0);
	std::fill(mx, mx + maxN, 0);
	std::fill(mxh, mxh + maxH, 0);
}


void Prepare() {
	std::cin >> n >> H >> F;
	//N = n * (H + 1);

	for (maxn t = 1, cnt = 0; t <= n; t++) for (maxh h = 0; h <= H; h++, cnt++)
		id[t][h] = cnt;

	for (maxn t = 1, cnt; t <= n; t++) {
		std::cin >> cnt;
		while (cnt--) {
			maxh h; std::cin >> h, ++c[id[t][h]];
		}
	}
}


void Process() {
	for (maxn t = 1; t <= n; t++) mx[id[t][H]] = c[id[t][H]], mxh[H] = std::max(mxh[H], mx[id[t][H]]);

	for (maxh h = H - 1; h >= 0; h--) for (maxn t = 1; t <= n; t++) {
		mx[id[t][h]] = mx[id[t][h + 1]] + c[id[t][h]];
		if (h + F <= H) mx[id[t][h]] = std::max(mx[id[t][h]], mxh[h + F] + c[id[t][h]]);
		mxh[h] = std::max(mxh[h], mx[id[t][h]]);
	}

	std::cout << mxh[0] << '\n';
}


int main() {
	//freopen("1231.inp", "r", stdin);
	//freopen("1231.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Init();
		Prepare();
		Process();
	}
}