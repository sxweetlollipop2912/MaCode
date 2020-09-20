#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 200001
#define maxH 500001

typedef long maxn;

maxn n, H, block[maxH], res, res_cnt;


void Prepare() {
	std::cin >> n >> H;

	for (maxn i = 0; i < n; i++) {
		maxn a; 
		std::cin >> a;
		if (!(i & 1)) ++block[0], --block[a];
		else ++block[H - a];
	}
}


void Process() {
	res = block[0], res_cnt = 1;

	for (maxn i = 1; i < H; i++) {
		block[i] += block[i - 1];
		if (block[i] == res) ++res_cnt;
		if (block[i] < res) res = block[i], res_cnt = 1;
	}

	std::cout << res << ' ' << res_cnt << '\n';
}


int main() {
	//freopen("domdom.inp", "r", stdin);
	//freopen("domdom.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}