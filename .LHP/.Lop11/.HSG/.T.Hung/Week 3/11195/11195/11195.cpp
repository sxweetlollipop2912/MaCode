// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 16
#define maxB (1 << n)
#define off(b, i) ((b) & (~(1 << (i))))

typedef int maxn, maxb, maxr;

maxn n;
maxr res;
maxb a[maxN];


void Prepare() {
	for (maxn i = 0; i < n; i++) {
		a[i] = maxB - 1;
		for (maxn j = 0; j < n; j++) {
			char c; std::cin >> c;
			if (c == '*') a[i] = off(a[i], j);
		}
	}
}


void Try(const maxn row, const maxb cl, const maxb dl, const maxn dr) {
	if (row == n) {
		++res; return;
	}

	maxb cur = a[row] & (~(cl | dl | dr));
	while (cur) {
		maxb pos = cur & (-cur);
		cur -= pos;
		Try(row + 1, cl | pos, (dl | pos) >> 1, (dr | pos) << 1);
	}
}


void Process() {
	res = 0;
	Try(0, 0, 0, 0);
	std::cout << res << '\n';
}


int main() {
	//freopen("11195.inp", "r", stdin);
	//freopen("11195.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int cntq = 0;
	while (std::cin >> n && n) {
		std::cout << "Case " << ++cntq << ": ";
		Prepare();
		Process();
	}
}