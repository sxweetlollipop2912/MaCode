#include <iostream>
#include <algorithm>

#define maxN 1001
#define cpm 8

typedef int maxn, maxt, maxa;

maxn n, res;
maxt t[maxN], prof[maxN], f[maxN], prev[maxN];


void Prepare() {
	for (maxn i = 0; i < n; i++) {
		double x;
		std::cin >> t[i] >> x;
		prof[i] = x * 100;
	}
}


void Process() {
	f[0] = prof[0] - cpm, prev[0] = 0, res = 0;

	for (maxn i = 1; i < n; i++) {
		f[i] = prof[i] - cpm, prev[i] = i;
		if (f[i - 1] >= cpm * (t[i] - t[i - 1] - 1) && f[i - 1] + prof[i] >= cpm * (t[i] - t[i - 1]) && f[i] < f[i - 1] + prof[i] - cpm * (t[i] - t[i - 1])) {
			f[i] = f[i - 1] + prof[i] - cpm * (t[i] - t[i - 1]);
			prev[i] = prev[i - 1];
		}
		if (f[res] < f[i]) res = i;
		else if (f[res] == f[i] && t[res] - t[prev[res]] > t[i] - t[prev[i]]) res = i;

	}

	if (f[res] <= 0) std::cout << "no profit\n";
	else {
		std::cout << f[res] / 100 << '.';
		if (f[res] % 100 < 10) std::cout << '0';
		std::cout << f[res] % 100 << ' ' << t[prev[res]] << ' ' << t[res] << '\n';
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) {
		Prepare();
		Process();
	}
}