//AC Kattis
#include <iostream>
#include <algorithm>

#define maxN 801
#define maxA 100001
#define minA -100001

typedef int maxn;
typedef long long maxa;

maxn n;
maxa x[maxN], y[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> x[i];
	for (maxn i = 0; i < n; i++) std::cin >> y[i];
}


void Process() {
	std::sort(x, x + n);
	std::sort(y, y + n);
	
	maxa res = 0;
	for (maxn i = 0; i < n; i++) res += x[i] * y[n - i - 1];
	std::cout << res << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	for (int cntq = 1; cntq <= q; cntq++) {
		std::cout << "Case #" << cntq << ": ";
		Prepare();
		Process();
	}
}