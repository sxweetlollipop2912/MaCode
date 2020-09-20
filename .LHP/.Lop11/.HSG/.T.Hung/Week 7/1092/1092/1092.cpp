#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxC 1000001
#define maxN 1001
#define left second
#define right first
#define none -1

typedef long maxc;
typedef int maxn;
typedef std::pair <maxc, maxc> ran_t;

maxc m, n, bit[maxC], res;
maxn W;
std::vector <ran_t> ran[maxC];


void Prepare() {
	std::cin >> m >> n >> W;

	for (maxn w = 0; w < W; w++) {
		maxc x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		ran[y1].push_back(ran_t(x1, x2));
	}
	for (maxc r = 0; r < m; r++) {
		ran[r].push_back(ran_t(n, n));
		std::sort(ran[r].begin(), ran[r].end(), std::greater <ran_t>());
	}
}


void Update(maxc i, maxc val) {
	++i;
	while (i <= m) bit[i] += val, i += (i & (-i));
}

maxc Sum(maxc i) {
	maxc re = 0; ++i;
	while (i != 0) re += bit[i], i -= (i & (-i));
	return re;
}


maxc find(const maxn r, const maxn L, const maxn R) {
	maxc re = -1;
	if (r >= 0)
		for (maxn i = 0; i < ran[r].size(); i++) if (ran[r][i].left > L && ran[r][i].left <= R + 1) re = std::max(re, ran[r][i].left);
	return re;
}


void Process() {
	for (maxc row = 0; row < m; row++) for (maxn i = 0; i < ran[row].size(); i++) {
		maxn l = ran[row][i].left, r = ran[row][i].right; maxc lim = -1;
		if (i && ran[row][i - 1].left == r + 1) res += Sum(r) - Sum(l - 1);
		else if ((lim = find(row - 1, l, r)) != -1) res += Sum(lim - 1) - Sum(l - 1);

	}
}