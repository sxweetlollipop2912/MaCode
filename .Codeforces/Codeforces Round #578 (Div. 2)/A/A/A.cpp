#include <iostream>
#include <algorithm>

typedef long maxa;
typedef int maxn;

maxn n;
maxa m, k;


void Prepare() {
	std::cin >> n >> m >> k;
}


void Process() {
	maxa h[2];
	bool p = 1, res = 1;
	std::cin >> h[p];

	for (maxn i = 1; i < n; i++) {
		p = !p;
		std::cin >> h[p];

		if (h[!p] < h[p] - k) {
			m = m - ((h[p] - k) - h[!p]);
			if (m < 0) res = 0;
		}
		else m += (h[!p] - std::max((maxa)0, (h[p] - k)));
	}

	if (res) std::cout << "YES\n";
	else std::cout << "NO\n";
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	while (q--) {
		Prepare();
		Process();
	}
}