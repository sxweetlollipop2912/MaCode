#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 2002
#define maxM 1001
#define left first
#define right second
#define ndec 1
#define MID 500000000

typedef int maxn, maxm;
typedef std::pair <maxn, maxn> ran;

maxn n, dec[maxN];
maxm m;
std::vector <ran> req[2];


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		bool t;
		maxn l, r;
		std::cin >> t >> l >> r;
		req[t].push_back(ran(l, r));
	}

	req[ndec].push_back(ran(0, 0));
	req[ndec].push_back(ran(n + 1, n + 1));
	std::sort(req[ndec].begin(), req[ndec].end());
}


maxn change(const maxn L, const maxn R) {
	maxn pr = 0;
	for (maxm i = 1; i < req[ndec].size(); i++) {
		maxn l = req[ndec][i].left; pr = std::max(pr, req[ndec][i - 1].right);
		if (pr >= R) return -1;
		if (l <= L || l <= pr) continue;
		return std::min(R, std::max(pr + 1, l));
	}
	return -1;
}


bool Process() {
	dec[0] = 0;
	for (maxm q = 0; q < req[!ndec].size(); q++) {
		maxn l = req[!ndec][q].left, r = req[!ndec][q].right;
		maxn c = change(l, r);

		if (c == -1) return 0;
		dec[c] = -1;
	}

	std::cout << "YES\n";
	for (maxn i = 1; i <= n; i++) {
		dec[i] += dec[i - 1];
		std::cout << MID + dec[i] << ' ';
	}

	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "NO";
}