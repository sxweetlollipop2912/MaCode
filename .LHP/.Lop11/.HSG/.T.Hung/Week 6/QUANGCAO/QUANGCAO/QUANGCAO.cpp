#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <iomanip>

#define maxS 172804
#define S 172800
#define next(s) ((s) + 86400)
//#define maxN 100001
#define num(c) ((c) - '0')
#define sec(h, m, s) ((h) * 60 * 60 + (m) * 60 + (s))
#define start(s) sec(num(s[0]) * 10 + num(s[1]), num(s[3]) * 10 + num(s[4]), num(s[6]) * 10 + num(s[7]))
#define end(s) sec(num(s[11]) * 10 + num(s[12]), num(s[14]) * 10 + num(s[15]), num(s[17]) * 10 + num(s[18]))

typedef long maxn, maxa, maxq;
typedef double maxr;
typedef std::string str;

maxn n, sum[maxS];


void Prepare() {
	std::cin >> n;

	str s; std::getline(std::cin, s);
	for (maxn i = 0; i < n; i++) {
		std::getline(std::cin, s);
		maxa st = start(s) + 1, en = end(s) + 1;
		//std::cout << st << ' ' << en << '\n';
		if (st <= en) ++sum[st], --sum[en + 1], ++sum[next(st)], --sum[next(en) + 1];
		else ++sum[0], --sum[en + 1], ++sum[st], --sum[next(en) + 1], ++sum[next(st)];
	}
}


maxr ratio(const maxa st, const maxa en) {
	//std::cout << st << ' ' << en << ' ' << next(en) << ' ' << sum[en] << ' ' << sum[next(en)] << ' ' << sum[st - 1] << '\n';
	if (st <= en) return (sum[(en)] - sum[st - (maxa)1]) / (maxr)((en)-(st)+(maxa)1);
	return (sum[next(en)] - sum[st - (maxa) 1]) / (maxr)(next(en)-(st)+(maxa)1);
	/*maxa t = SEC - st + 1 + en, p = sum[SEC] - sum[st - 1] + sum[en];
	std::cout << sum[SEC] << ' ' << sum[st - 1] << ' ' << st << ' ' << en << '\n';
	return p / (maxr)t;*/
}


void Process() {
	for (maxn i = 1; i <= S; i++) sum[i] += sum[i - 1];
	for (maxn i = 1; i <= S; i++) sum[i] += sum[i - 1];

	std::cout << std::fixed;
	std::cout << std::setprecision(5);

	maxq q; std::cin >> q;
	str s; std::getline(std::cin, s);
	while (q--) {
		std::getline(std::cin, s);
		maxa st = start(s) + 1, en = end(s) + 1;
		std::cout << ratio(st, en) << '\n';
	}
}


int main() {
	//freopen("quangcao.inp", "r", stdin);
	//freopen("quangcao.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}