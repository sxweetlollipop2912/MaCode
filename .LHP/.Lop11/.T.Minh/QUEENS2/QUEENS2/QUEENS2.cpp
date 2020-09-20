#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>

#define maxN 31
#define maxB ((1 << n) - 1)
#define off(b, i) ((b) & (~(1 << (i))))

typedef int maxn, maxb, maxr;

maxn n, res_cnt;
maxb res[maxN];


void Prepare() {
	std::cin >> n;
}


bool Try(const maxn row, const maxb cl, const maxb dl, const maxn dr) {
	if (row == n) return 1;

	maxb cur = maxB & (~(cl | dl | dr));
	while (cur) {
		maxb pos = cur & (-cur);
		cur -= pos;
		res[row] = pos, ++res_cnt;
		if (Try(row + 1, cl | pos, (dl | pos) >> 1, (dr | pos) << 1)) return 1;
	}
	--res_cnt;
	return 0;
}


void Process() {
	if (n == 2) std::cout << "1\n1 0";
	else if (n == 3) std::cout << "2\n1 3 0";
	else {
		Try(0, 0, 0, 0);
		std::cout << res_cnt << '\n';
		for (maxn i = 0; i < res_cnt; i++) std::cout << log2(res[i]) + 1 << ' ';
		for (maxn i = res_cnt; i < n; i++) std::cout << "0 ";
	}
}


int main() {
	//freopen("queens2.inp", "r", stdin);
	//freopen("queens2.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}