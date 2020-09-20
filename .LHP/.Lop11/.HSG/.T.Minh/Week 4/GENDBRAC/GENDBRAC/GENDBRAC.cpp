#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 36
#define LEN (2 * n)
#define erase(s) s.erase(s.size() - 1)
#define LIM 30000

typedef int maxn;
typedef std::string str;

maxn n, k, CNT;
str s;


void Prepare() {
	std::cin >> n >> k;
}


void Try(str& s, const maxn cnt, const maxn i, const maxn mx) {
	if (CNT == LIM) return;
	if (i == LEN) {
		if (!cnt && mx == k) std::cout << s << '\n', ++CNT;
		return;
	}
	if ((mx != k && i + (k - cnt) - 1 >= LEN - k) || (cnt > LEN - i)) return;

	s += '(';
	if (cnt != k) Try(s, cnt + 1, i + 1, std::max(mx, cnt + 1));
	erase(s); s += ')';
	if (cnt != 0) Try(s, cnt - 1, i + 1, mx);
	erase(s);
}


void Process() {
	Try(s, 0, 0, 0);
}


int main() {
	//freopen("gendbrac.inp", "r", stdin);
	//freopen("gendbrac.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}