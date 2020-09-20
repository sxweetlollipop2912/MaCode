#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 200002
#define maxA 200000001

typedef long maxn, maxa;
typedef std::string str;

maxn n;
maxa o[maxN], bit[maxN];


void Update(maxn i, maxa val) {
	while (i <= n) bit[i] += val, i += (i & (-i));
}
maxa Sum(maxn i) {
	maxa re = 0;
	while (i > 0) re += bit[i], i -= (i & (-i));
	return re;
}


void Prepare() {
	std::fill(bit, bit + maxN, 0);
	for (maxn i = 1; i <= n; i++) {
		std::cin >> o[i];
		Update(i, o[i]);
	}
}
 

void Process() {
	str s;
	while (std::cin >> s && s != "END") {
		if (s == "S") {
			maxn x; maxa a; std::cin >> x >> a;
			Update(x, a - o[x]);
			o[x] = a;
		}
		else {
			maxn x, y; std::cin >> x >> y;
			std::cout << Sum(y) - Sum(x - 1) << '\n';
		}
	}
}


int main() {
	//freopen("12086.inp", "r", stdin);
	//freopen("12086.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) {
		Prepare();
		Process();
	}
}