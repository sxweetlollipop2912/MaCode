// AC
#include <iostream>
#include <algorithm>

#define maxN 101
#define cost1(x, y, a, b) ((x) + 2 * (y) + (b))
#define cost2(x, y, a, b) ((x) * 2 + (a) + (b))

typedef int maxn, maxa;

maxn n;
maxa a[maxN], res;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
	std::sort(a, a + n);
}


void Process() {
	res = 0; maxn i;
	for (i = n - 2; i > 1; i -= 2)
		res += std::min(cost1(a[0], a[1], a[i], a[i + 1]), cost2(a[0], a[1], a[i], a[i + 1]));

	std::cout << (res += (i == 0) ? a[1] : (i == 1) ? a[2] + a[0] + a[1] : a[0]);
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}