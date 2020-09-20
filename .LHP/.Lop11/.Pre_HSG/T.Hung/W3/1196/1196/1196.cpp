// AC UVa
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 10001
#define fi first
#define se second

typedef int maxn, maxa;
typedef std::pair <maxa, maxa> pair;

maxn n;
pair a[maxN];
std::vector <maxa> bs;


void Prepare() {
	for (maxn i = 0; i < n; i++) std::cin >> a[i].fi >> a[i].se;
	std::sort(a, a + n);
	bs.clear();
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		maxn ii = std::upper_bound(bs.begin(), bs.end(), a[i].se) - bs.begin();
		if (ii == bs.end() - bs.begin()) bs.push_back(a[i].se);
		else bs[ii] = a[i].se;
	}
	std::cout << bs.size() << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) {
		Prepare();
		Process();
	}
	std::cout << "*\n";
}