#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 10
#define MONEY (maxa)1000
#define num(c) ((c) - '0')
#define ctrans 1
#define cplus(x) (!(x) ? 0 : (x) + 1)

typedef int maxn;
typedef long maxa;
typedef std::string str;

str s, mn[maxN] = { "1","10","100","1000","10000","100000","1000000","10000000","100000000","1000000000" };
bool add = 0;
maxa res, cost[maxN] = { 0,10,30,61,103,156,220,295,381,489 };


void Prepare() {
	std::cin >> s;
}


maxa Cal_cost(const str& st, const str& s) {
	if (st == s) return 0;

	maxa re = -1 - add; maxn cnt0 = 0, cnt1 = 0;
	for (maxn i = 0; i < s.size(); i++) cnt1 += s[i] == '1', cnt0 += s[i] == '0', re += cplus(num(s[i]));
	//std::cout << re << '\n';
	if (cnt0 == s.size() - 1) {
		if (s[0] == '1') return 0;
		if (s[0] == '2') return s.size() == 1 ? 2 : (cplus(9) + ctrans) * (s.size() - 2) + cplus(10) - add;
		return cplus(num(s[0]) - 1) - add + (cplus(9) + ctrans) * (s.size() - 1);
	}

	if (cnt1 != 0) re = re - cplus(1) + 1;
	//std::cout << re << '\n';
	maxn trans = (s.size() - (bool)(cnt1) - cnt0) * ctrans - (s[s.size() - 1] != '0') * ctrans;
	//std::cout << trans << '\n';
	return !trans && s.substr(0, s.size() - 1) != mn[s.size() - 2] ? re + ctrans : re + trans;
}


void Process() {
	add = s.size() != 1, res = cost[s.size() - 1] + Cal_cost(mn[s.size() - 1], s);
	//std::cout << res << ' ';
	std::cout << MONEY - res << '\n';
}


int main() {
	//freopen("mgame.inp", "r", stdin);
	//freopen("mgame.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long t; std::cin >> t;

	while (t--) {
		Prepare();
		Process();
	}
}