#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 26
#define maxA (1 << 26)
#define qualified ((1 << 26) - 1)
#define on(b, i) (b | (1 << i))

typedef int maxn;
typedef long maxa, maxr;
typedef std::string str;

maxn n;
maxa a[maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		str s;
		std::cin >> s;
		for (int is = 0; is < s.size(); is++) a[i] = on(a[i], s[is] - 'a');
	}
}


maxr Try(const maxn i, maxa b) {
	if (i == n) return b == qualified;
	return Try(i + 1, b) + Try(i + 1, b | a[i]);
}


void Process() {
	std::cout << Try(0, 0);
}


int main() {
	//freopen("font.inp", "r", stdin);
	//freopen("font.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}