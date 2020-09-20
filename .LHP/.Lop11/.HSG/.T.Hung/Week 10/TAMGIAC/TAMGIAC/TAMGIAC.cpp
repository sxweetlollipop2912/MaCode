#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 201
#define len(n) (2 * ((n) - 1) + 1)

typedef int maxn;
typedef std::string str;

maxn n, mx[maxN][maxN], hres, res;
bool g[maxN][maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 1; i <= n; i++) {
		str s; std::cin >> s;
		for (maxn j = i; j - i < s.size(); j++) g[i][j] = s[j - i] == '-';
	}
}


void Process() {
	hres = 0;

	for (maxn i = 1; i <= n; i++) for (maxn j = i; j < i + len(n - i + 1); j += 2)
		mx[i][j] = g[i][j] ? std::min(mx[i - 1][j - 1], mx[i - 1][j + 1]) * g[i - 1][j] + 1 : 0, hres = std::max(hres, mx[i][j]);

	for (maxn i = n; i >= 1; i--) for (maxn j = i + 1; j < i + len(n - i + 1); j += 2) {
		mx[i][j] = g[i][j] ? std::min(mx[i + 1][j - 1], mx[i + 1][j + 1]) * g[i + 1][j] + 1 : 0, hres = std::max(hres, mx[i][j]);
	}

	std::cout << hres * hres;
}


int main() {
	//freopen("tamgiac.inp", "r", stdin);
	//freopen("tamgiac.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}