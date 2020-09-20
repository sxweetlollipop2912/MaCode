#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define maxN 2000001
#define maxA 27

typedef long long maxn;
typedef int maxa;
typedef std::string str;

maxn na, ns, res, cnt[maxA];
maxa a[maxN], s[maxN];


void Prepare() {
	str as, ss; std::cin >> as >> ss;

	na = as.size(), ns = ss.size();
	for (maxn i = 0; i < na; i++) a[i] = as[i] - 'a';
	for (maxn i = 0; i < ns; i++) s[i] = ss[i] - 'a';
}


void Process() {
	res = 0;
	for (maxn i = 0; i < ns; i++) {
		if (i < na) ++cnt[a[i]];
		if (ns - i < na) --cnt[a[na - (ns - i) - 1]];
		res += cnt[s[i]];
		//std::cout << i << ' ' << s[i] << ' ' << cnt[s[i]] << '\n';
	}
	std::cout << res;
}


int main() {
	//freopen("sosanh.inp", "r", stdin);
	//freopen("sosanh.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}