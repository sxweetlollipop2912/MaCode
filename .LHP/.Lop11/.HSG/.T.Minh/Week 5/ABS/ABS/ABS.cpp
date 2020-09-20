#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 183
#define maxK 1000000000000000001
#define LIM(n) (((n) - 1) / 2)

typedef int maxn;
typedef long long maxa;
typedef std::string str;

maxn n;
maxa k, f[maxN][maxN];
str res;


bool Process() {
	for (maxn i = 0; i <= n + 1; i++) f[i][0] = 1;
	for (maxa i = n; i >= 1; i--) for (maxa j = 1; j <= LIM(n); j++) 
		f[i][j] = std::min(maxK, f[i + 1][j - 1] + f[i + 1][j]);
	for (maxa i = 1; i <= n; i++) for (maxa j = 1; j <= LIM(n); j++) 
		f[i][j] = std::min(maxK, f[i][j] + f[i][j - 1]);

	//std::cout << f[1][LIM(n)] << '\n';
	if (f[1][LIM(n)] < k) return 0;

	res = "";
	for (maxn pos = 1, cnt = LIM(n); pos <= n; pos++) {
		//std::cout << pos + 1 << ' ' << cnt - 1 << ' ' << f[pos + 1][cnt - 1] << ' ' << k << '\n';
		if (!cnt || f[pos + 1][cnt - 1] < k) res += 'B', k -= f[pos + 1][std::max(0, cnt - 1)];
		else res += 'A', --cnt;
	}

	std::cout << res << '\n';
	return 1;
}


int main() {
	//freopen("abs.inp", "r", stdin);
	//freopen("abs.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n >> k) if (!Process()) std::cout << "-1\n";
}