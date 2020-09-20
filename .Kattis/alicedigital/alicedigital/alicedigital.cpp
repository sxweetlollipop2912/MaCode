// AC Kattis
#include <iostream>
#include <algorithm>

#define maxN 100002
#define dumm n

typedef int maxn, maxa;

maxn n;
maxa m, a[maxN], sum[maxN];


void Prepare() {
	std::cin >> n >> m;
	for (maxn i = 0; i < n; i++) std::cin >> a[i], sum[i] = 0;
}


void Process() {
	for (maxn l = dumm, r = 0; r < n; r++) {
		if (a[r] == m)  l = r;
		else if (a[r] < m) l = dumm;
		sum[l] += a[r];
	}
	for (maxn l = n - 1, r = dumm; l >= 0; l--) {
		if (a[l] == m)  r = l;
		else if (a[l] < m) r = dumm;
		sum[r] += a[l];
	}
	std::cout << *std::max_element(sum, sum + n) - m << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;

	while (t--) {
		Prepare();
		Process();
	}
}