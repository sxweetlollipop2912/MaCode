#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>

#define maxN 1000001

typedef long maxn;
typedef long long maxa;
typedef std::multiset <maxa> mset_t;

maxn day;
maxa res;
mset_t set;


void Process() {
	res = 0;
	set.clear();

	while (day--) {
		maxn n; std::cin >> n;
		maxa a;
		while (n--) std::cin >> a, set.insert(a);
		mset_t::iterator st = set.begin(), en = set.end(); --en;
		res += *en - *st;
		set.erase(en); set.erase(st);
	}

	std::cout << res << '\n';
}


int main() {
	//freopen("11136.inp", "r", stdin);
	//freopen("11136.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> day && day) 
		Process();
}