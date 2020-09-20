#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define maxN 10001
#define num(a, b, c, d, e) ((a) * (1e12) + (b) * (1e9) + (c) * (1e6) + (d) * (1e3) + (e))

typedef int maxn;
typedef long long maxa;

maxn n, res, res_cnt;
std::vector <maxa> v;


void Process() {
	maxa a[5];
	v.clear();

	while (n--) {
		std::cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
		std::sort(a, a + 5);
		v.push_back(num(a[0], a[1], a[2], a[3], a[4]));
	}
	std::sort(v.begin(), v.end());

	maxn cnt = 1;  res = res_cnt = 0;
	v.push_back(0);
	for (maxn i = 1; i < v.size(); i++) {
		if (v[i] == v[i - 1]) ++cnt;
		else {
			if (res == cnt) ++res_cnt;
			if (res < cnt) res = cnt, res_cnt = 1;
			cnt = 1;
		}
	}

	std::cout << (res * res_cnt) << '\n';
}


int main() {
	//freopen("tuongdong.inp", "r", stdin);
	//freopen("tuongdong.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) Process();
}