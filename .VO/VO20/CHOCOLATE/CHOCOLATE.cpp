#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 18
#define maxM 257

typedef int maxn, maxm;
typedef long long maxa;

maxn n, a[maxM], b[maxM], ad[maxN], V[maxN];
maxm m;
maxa K, f[maxN];
bool done[maxN], mx[maxN];


void Prepare() {
	std::cin >> n >> K >> m;
	for (maxm i = 0; i < m; i++) std::cin >> a[i] >> b[i], mx[b[i]] = 1, ad[a[i]] = b[i], ad[b[i]] = a[i];

	f[0] = 1;
	for (maxn i = 1; i <= n; i++) f[i] = f[i - 1] * i;
}


bool Check(maxn v[]) {
	for (maxm i = 0; i < m; i++) if (v[a[i] - 1] >= v[b[i] - 1]) return 0;
	return 1;
}


bool Process() {
	if (K > f[n]) return 0;

	if (!m) {
		--K;
		for (maxn i = 0; i < n; i++) {
			maxn x = K / f[n - i - 1] + 1;
			if (x > n - i) return 0;
			K %= f[n - i - 1]; V[i] = 0;
			for (maxn cnt = 0; cnt != x; V[i]++) cnt += !done[V[i] + 1];
			done[V[i]] = 1;
			std::cout << V[i] << ' ';
		}
		return 1;
	}

	if (n <= 10) {
		for (maxn i = 1; i <= n; i++) V[i - 1] = i;
		do {
			K -= Check(V);
			if (K) continue;
			for (maxn i = 0; i < n; i++) std::cout << V[i] << ' '; return 1;
		} while (std::next_permutation(V, V + n));
		return 0;
	}

	if (K == 1) {
		for (maxn i = 1; i <= n; i++) {
			if (V[i - 1]) continue;
			if (!mx[i] || V[ad[i] - 1]) for (V[i - 1] = 1; done[V[i - 1]]; V[i - 1]++);
			else {
				for (V[ad[i] - 1] = 1; done[V[ad[i] - 1]]; V[ad[i] - 1]++);
				done[V[ad[i] - 1]] = 1, V[i - 1] = V[ad[i] - 1] + 1;
			}
			done[V[i - 1]] = 1;
		}
		for (maxn i = 0; i < n; i++) std::cout << V[i] << ' '; return 1;
	}

	return 0;
}


int main() {
	freopen("chocolate.inp", "r", stdin);
	freopen("chocolate.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "poor professor";
}