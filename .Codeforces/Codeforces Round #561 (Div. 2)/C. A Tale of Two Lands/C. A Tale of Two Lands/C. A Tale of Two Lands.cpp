#include <iostream>
#include <algorithm>

#define maxN 200001

typedef long maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], res;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) 
		std::cin >> a[i], a[i] = abs(a[i]);

	std::sort(a, a + n);
}


void Process() {
	maxn pos = 0;
	for (maxn i = 1; i < n; i++) {
		while (a[pos] < (a[i] + 2 - 1) / 2) ++pos;
		res += i - pos;
	}
	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}