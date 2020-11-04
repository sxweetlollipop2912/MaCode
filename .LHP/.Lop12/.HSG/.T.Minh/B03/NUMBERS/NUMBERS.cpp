#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>

#define maxN 19
#define DIGIT 10
#define maxD 12
#define maxA ((maxa)1e18)

typedef int maxn;
typedef long long maxa;
typedef std::vector <int> d_t;

maxa a, b, f[maxN][maxD][maxD][maxD], done[maxN][maxD][maxD][maxD], res;
d_t d;


void Prepare() {
	std::cin >> a >> b;
}


void Gen(maxa a, d_t& d) {
	d.clear(); d.push_back(0);
	while (a != 0) {
		d.push_back(a % 10);
		a /= 10;
	}
}


maxa DP(const maxn pos, const int d1, const int d2, const int lim, d_t& d) {
	if (pos == d.size() - 1) return 1;
	if (done[pos][d1][d2][lim]) return f[pos][d1][d2][lim];
	done[pos][d1][d2][lim] = 1;

	maxa &res = f[pos][d1][d2][lim];

	res = 0;
	if (d2 == DIGIT) res += DP(pos + 1, d2, DIGIT, DIGIT, d);

	for (int i = 0; i < lim; i++) {
		if (i == d1 || i == d2 || (d2 == DIGIT && !i)) continue;
		res += DP(pos + 1, d2, i, DIGIT, d);
	}
	if (lim != DIGIT && lim != d1 && lim != d2) res += DP(pos + 1, d2, lim, d[d.size() - (pos + 1) - 1], d);

	return res;
}


void Process() {
	Gen(b, d);
	memset(done, 0, sizeof(done));
	res = DP(0, DIGIT, DIGIT, d.back(), d);
	
	Gen(std::max(a - 1, (maxa)0), d);
	memset(done, 0, sizeof(done));
	res -= DP(0, DIGIT, DIGIT, d.back(), d);

	if (!a) ++res;
	std::cout << res;
}


int main() {
	//freopen("numbers.inp", "r", stdin);
	//freopen("numbers.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}