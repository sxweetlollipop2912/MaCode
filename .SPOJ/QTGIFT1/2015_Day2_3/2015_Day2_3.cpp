// TLE SPOJ
#include <iostream>

#define maxN 1000003

typedef long maxn;
typedef long maxa;

maxn n, K;
maxa d[maxN], f[maxN], sum[maxN], re[maxN], a, res;
maxn dq[maxN * 2], back = maxN + 1, front = maxN;


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> n >> K >> a;

	sum[2] = a, re[2] = a, f[1] = -a;
	dq[--back] = 0;

	for (maxn i = 3; i < n + 2; i++) {
		std::cin >> a;
		re[i] = sum[i] = a + sum[i - 1];
		f[i - 1] -= a;

		maxn x = i - 2; 
		d[x] = f[i - 2];

		while (back <= front && d[dq[back]] < d[x]) ++back;
		dq[--back] = x;
		while (dq[front] < i - K) --front;

		f[i] = d[dq[front]];
		re[i] += re[dq[front]] - sum[dq[front] + 1];

		if (re[i] > res) res = re[i];
	}

	std::cout << res;
}