#include <iostream>
#include <algorithm>
#include <string>

#define maxN 17
#define MAXB (maxb)(((maxb)1 << (maxb)n) - (maxb)1)
#define off(b, p) ((b) & ~(p))
#define on(b, p) ((b) | (p))

typedef int maxn;
typedef long long maxb, maxr;

maxn n;
maxb a[maxN];
maxr res;


void Prepare() {
	res = 1;
	for (maxn i = 0; i < n; i++) {
		std::string s; std::cin >> s;
		res *= s == "?" ? n : s.size();
		a[i] = 0;
		if (s == "?") a[i] = MAXB;
		else for (maxn is = 0; is < s.size(); is++) a[i] = on(a[i], (maxb)1 << (maxb)(s[is] - 'A'));
	}
}


maxr Try(const maxb dl, const maxb dr, const maxb ex, const maxb x2, const maxb x1, const maxn i) {
	//std::cout << dl << ' ' << dr << ' ' << ex << ' ' << x2 << ' ' << x1 << ' ' << i << ' ' << a[i] << '\n';
	if (i == n) return 1;

	maxr re = 0;
	maxb b = ~(dl | dr | ex | (x2 << 1) | (x2 >> 1) | (x1 << 2) | (x1 >> 2) | (~a[i])); //std::cout << b << '\n';

	while (b != 0) {
		maxb p = b & (-b); b -= p;
		if (p > MAXB) break;
		re += Try(on(dl, p) << 1, on(dr, p) >> 1, on(ex, p), x1, p, i + 1);
	}

	return re;
}


void Process() {
	//res = 1;
	//for (maxn i = 0; i < n; i++) res *= n;
	res -= Try(0, 0, 0, 0, 0, 0);
	std::cout << res << '\n';
	//std::cout << Try(0, 0, 0, 0, 0, 0);
}


int main() {
    freopen("bseq.inp", "r", stdin);
    //freopen("bseq.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

	while (std::cin >> n && n) {
		Prepare();
		Process();
	}
}
