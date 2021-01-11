#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <vector>

#define maxN 10002
#define isSCP(x) (((maxn)sqrt(x) * (maxn)sqrt(x)) == (x))

typedef int maxn;

int q;
maxn n, f[maxN];


void Prepare() {
	std::cin >> q;
}


void Process() {
	std::vector <maxn> scp;

	for (maxn i = 1; i <= maxN - 2; i++) {
		if (isSCP(i)) {
			f[i] = 1; scp.push_back(i);
		}
		else {
			f[i] = i;
			for (maxn j = 0; j < scp.size(); j++) f[i] = std::min(f[i], f[scp[j]] + f[i - scp[j]]);
		}
	}

	while (q--) {
		maxn n; std::cin >> n;
		std::cout << f[n] << '\n';
	}
}


int main() {
	//freopen("binhphuong.inp", "r", stdin);
	//freopen("binhphuong.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}