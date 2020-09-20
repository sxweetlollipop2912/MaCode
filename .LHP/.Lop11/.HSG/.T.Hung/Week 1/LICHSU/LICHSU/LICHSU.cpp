#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

#define maxN 25001
#define maxA 300
#define go 5

typedef int maxn;
typedef long maxt;
typedef char maxa;
typedef std::string str;

maxn n, cnt[maxA];
maxt ori[maxA], res;
std::vector <maxa> v;


void Prepare() {
	str s;
	std::cin >> n >> s;

	std::fill(cnt, cnt + maxA, 0);
	v.clear();
	for (maxn i = s.size() - 1; i >= 0; i--) {
		if (!cnt[s[i]]) {
			v.push_back(s[i]);
			ori[s[i]] = i + 1;
		}
		++cnt[s[i]];
	}
}


void Process() {
	res = 0;
	maxn cpos = 0;
	for (maxn i = v.size() - 1; i >= 0; i--) {
		cpos += cnt[v[i]];
		res += (ori[v[i]] - cpos) * go * cnt[v[i]];
	}
	std::cout << res << '\n';
}


int main() {
	//freopen("lichsu.inp", "r", stdin);
	//freopen("lichsu.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	while (q--) {
		Prepare();
		Process();
	}
}