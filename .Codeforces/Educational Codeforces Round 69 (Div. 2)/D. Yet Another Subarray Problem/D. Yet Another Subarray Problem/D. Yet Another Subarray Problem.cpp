#include <iostream>
#include <algorithm>

#define maxN 300001
#define maxM 11
//#define maxK 1000000001

typedef long long maxn, maxa;

maxn n;
maxa M, K, a[maxN], f[maxM], res;


void Prepare() {
	std::cin >> n >> M >> K;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
	res = 0;

	for (maxn r = 0; r < n; r++) {
		maxa sum = 0, f_tmp = 0;
		for (maxn l = r; l > r - M && l >= 0; l--) {
			sum += a[l];
			f_tmp = std::max(f_tmp, sum - K);
		}
		f[r % M] = std::max(f_tmp, f[r % M] + sum - K);
		res = std::max(res, f[r % M]);
	}

	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}