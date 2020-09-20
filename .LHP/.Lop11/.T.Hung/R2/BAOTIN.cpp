#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>

#define maxN 100003
#define INF (maxa)10000000001

typedef long maxn;
typedef long double maxa;

maxn n;
maxa K, a[maxN], b[maxN], t[maxN], L, R;


void Prepare() {
	std::cin >> K >> n;
	L = 0, R = 0;
	a[0] = 0;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i], R = std::max(R, a[i]);
}


bool Check(const maxa T) {
	std::fill(t, t + n + 2, T);
	for (maxn i = 0; i <= n; i++) b[i] = a[i];

	b[0] = std::min(b[1], b[0] + t[0]);
	t[0] -= (b[0] - a[0]);

	for (maxn i = 1; i <= n; i++) {
		b[i - 1] = std::min(b[i - 1] + t[i - 1], b[i]);
		t[i - 1] = 0;
		maxa time = std::max((maxa)0, b[i] - b[i - 1] - K);
		b[i] -= time, t[i] -= time;
		if (t[i] < 0) return 0;
	}
	return 1;
}


void Process() {
	//std::cout << L << ' ' << R << '\n';
	maxa m = (L + R) / (maxa)2;
	while (L != m && R != m) {
		if (Check(m)) R = m;
		else L = m;
		//std::cout << L << ' ' << R << ' ' << m << '\n';
		m = (L + R) / (maxa)2;
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(3);
	std::cout << m;
}


int main() {
	freopen("baotin.inp", "r", stdin);
	freopen("baotin.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}