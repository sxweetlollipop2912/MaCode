// AC Kattis
#include <iostream>
#include <algorithm>

#define maxN 1000001

typedef long long maxn;

maxn n, X, a[maxN];


void Prepare() {
	std::cin >> n >> X;
	for (maxn i = 0; i < n; i++) a[i] = i + 1;
}


bool Process() {
	maxn pos = 1, cur;
	for (cur = 1; X && cur < n - 1; cur++) {
		pos = std::min(n - 1 - cur, X);
		a[pos] = cur, X-= pos;
	}
	if (X) return 0;

	for (maxn i = 0; i < pos; i++) a[i] = cur, ++cur;
	for (maxn i = pos + 1; cur < n; i++) a[i] = cur, ++cur;
	a[n - 1] = n;
	for (maxn i = 0; i < n; i++) std::cout << a[i] << ' ';

	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "-1";
}