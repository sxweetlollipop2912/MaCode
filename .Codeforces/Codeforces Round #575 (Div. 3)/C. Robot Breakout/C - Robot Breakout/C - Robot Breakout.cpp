#include <iostream>
#include <algorithm>

#define maxN 100001
#define minC -100001
#define maxC 100001
#define left 0
#define up 1
#define right 2
#define down 3

typedef long maxn, maxa;

maxn n;
maxa l, r, u, d;


void Prepare() {
	std::cin >> n;

	l = d = minC, r = u = maxC;
	for (maxn i = 0; i < n; i++) {
		bool f[4];
		maxa x, y;
		std::cin >> x >> y >> f[0] >> f[1] >> f[2] >> f[3];

		if (!f[left]) l = std::max(l, x - 1);
		if (!f[right]) r = std::min(r, x + 1);
		if (!f[up]) u = std::min(u, y + 1);
		if (!f[down]) d = std::max(d, y - 1);
	}
}


bool Process() {
	if (r - 1 <= l || u - 1 <= d) return 0;
	std::cout << "1 " << l + 1 << ' ' << d + 1 << '\n';
	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long q;
	std::cin >> q;

	while (q--) {
		Prepare();
		if (!Process()) std::cout << "0\n";
	}
}