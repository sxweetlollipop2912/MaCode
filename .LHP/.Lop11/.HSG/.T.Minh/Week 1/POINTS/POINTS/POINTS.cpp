#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 10001

typedef long long maxn;
typedef std::pair <bool, bool> p_t;

maxn n, cnt[2][2], res;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) {
		maxn x, y;
		std::cin >> x >> y;
		++cnt[x & 1][y & 1];
	}
}


void Process() {
	res = 0;

	for (int ax = 0; ax <= 1; ax++) for (int ay = 0; ay <= 1; ay++) for (int bx = 0; bx <= 1; bx++) for (int by = 0; by <= 1; by++) for (int cx = 0; cx <= 1; cx++) for (int cy = 0; cy <= 1; cy++) {
		if ((ax * by - ay * bx + bx * cy - by * cx + cx * ay - cy * ax) & 1) continue;

		if (p_t(ax, ay) == p_t(bx, by)) {
			if (p_t(ax, ay) == p_t(cx, cy)) res += ((cnt[ax][ay] * (cnt[ax][ay] - 1) * (cnt[ax][ay] - 2)) / 6);
			else res += (((cnt[ax][ay] * (cnt[ax][ay] - 1)) / 2) * cnt[cx][cy]);
		}
		else if (p_t(ax, ay) == p_t(cx, cy)) res += (((cnt[ax][ay] * (cnt[ax][ay] - 1)) / 2) * cnt[bx][by]);
		else if (p_t(bx, by) == p_t(cx, cy)) res += (((cnt[bx][by] * (cnt[bx][by] - 1)) / 2) * cnt[ax][ay]);
		else res += cnt[ax][ay] * cnt[bx][by] * cnt[cx][cy];
	}

	std::cout << res;
}


int main() {
	//freopen("points.inp", "r", stdin);
	//freopen("points.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}