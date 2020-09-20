#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>

#define maxN 100001
#define left second
#define right first

typedef long maxn, maxa;
typedef std::pair <maxa, maxa> p_t;
typedef std::multiset <maxa, std::greater<maxa> > set_t;

maxn n, k, res;
p_t a[maxN];
set_t set;

void Prepare() {
	std::cin >> n >> k;
	for (maxn i = 0; i < n; i++) std::cin >> a[i].left >> a[i].right;
	std::sort(a, a + n);
}


void Process() {
	res = n;
	for (maxn i = 0; i < n; i++) {
		set_t::iterator it = set.lower_bound(a[i].left);
		if (it != set.end()) {
			set.erase(*it);
			set.insert(a[i].right);
		}
		else if (set.size() < k) set.insert(a[i].right);
		else --res;
	}
	std::cout << res;
}


int main() {
	//freopen("dauthu.inp", "r", stdin);
	//freopen("dauthu.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}