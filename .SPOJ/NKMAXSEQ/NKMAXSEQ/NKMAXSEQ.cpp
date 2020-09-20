// SPOJ - full test
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 50002

typedef long maxn;
typedef long long maxa;

struct group_t {
	maxn begin, end;
	maxa max;
};
group_t newGr_t(maxn begin, maxn end, maxa max) {
	group_t re;
	re.begin = begin; re.end = end; re.max = max;
	return re;
}

maxn n, gr[maxN], group_cnt, res;
maxa a[maxN], mx[maxN], sum[maxN], p; 
std::vector <group_t> group;


void Prepare() {
	std::cin >> n >> p;

	gr[0] = -1;
	for (maxn i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum[i] = sum[i - 1] + a[i];

		if (mx[i - 1] > 0) {
			gr[i] = gr[i - 1];
			mx[i] = mx[i - 1] + a[i];

			group.back().end = i;
			group.back().max = mx[i];
		}

		else {
			gr[i] = gr[i - 1] + 1;
			mx[i] = a[i];
			group.push_back(newGr_t(i, i, mx[i]));
		}
	}

	group_cnt = group.size();
}


maxa getSum(const maxn &l, const maxn &r) {
	return sum[r] - sum[l - 1];
}

maxa cal(const maxn &gr_l, const maxn &r) {
	return getSum(group[gr_l].end + 1, r) + group[gr_l].max;
}


bool Try(maxn &gr_l,const maxn &r) { // gr_l < gr[r]
	if (gr_l < 0 || cal(gr_l, r) < p) return 0;

	while (gr_l - 1 >= 0 && cal(gr_l - 1, r) >= p) gr_l--;
	return 1;
}


void Process() {
	maxn gr_l = group_cnt - 1;

	for (maxn r = n; r >= 1; r--) {
		if (mx[r] < p) continue;
		res = std::max(res, r - group[gr[r]].begin + 1);

		gr_l = std::min(gr_l, gr[r] - 1);
		if (!Try(gr_l, r)) continue;

		res = std::max(res, r - group[gr_l].begin + 1);
	}

	if (!res) res = -1;
	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}