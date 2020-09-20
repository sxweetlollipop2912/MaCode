#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 41

typedef int maxn;
typedef long maxr;

maxn n;
maxr res;
int a[maxN];


void Prepare() {
	std::cin >> n;
}


bool Check(maxn size) {
	maxn pos = size - 1;
	for (maxn len = 1, i; len <= (pos + 1) / 2; len++) {
		for (i = 0; i < len; i++) if (a[pos - len + 1 + i] != a[pos - 2 * len + 1 + i]) break;
		if (i == len) return 0;
	}
	return 1;
}


maxr Try(const maxn size, const maxn pos) {
	if (!Check(size)) return 0;
	if (pos == n - 1) return 1;

	maxr re = 0;
	a[size] = 1; re += Try(size + 1, pos + 1);
	a[size] = 2; re += Try(size + 1, pos + 1);
	a[size] = 3; re += Try(size + 1, pos + 1);

	return re;
}


void Process() {
	std::cout << Try(0, -1);
}


int main() {
	freopen("tchuan.inp", "r", stdin);
	freopen("tchuan.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}