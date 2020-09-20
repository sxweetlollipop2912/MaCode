#include <iostream>
#include <algorithm>

#define maxN 200001

typedef long maxn;
typedef long long maxa;

maxn n;
maxa K, a[maxN], res;


void Prepare() {
	std::cin >> n >> K;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
	maxa left = 0;

	for (maxn i = n - 1; i >= 0; i--) {
		a[i] = std::max(a[i] - left, (maxa)0);
		res += (a[i] + K - 1) / K, left = K * ((a[i] + K - 1) / K) - a[i];
	}

	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}