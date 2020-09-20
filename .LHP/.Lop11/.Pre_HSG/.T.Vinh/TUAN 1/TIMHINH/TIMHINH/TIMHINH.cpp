#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1002
#define maxK 0
#define B 0
#define W 1

typedef long long maxn;

maxn n, s[2][maxN], res_size, res_cnt;


void Prepare() {
	std::cin >> n;
}



void Process() {
	res_size = res_cnt = 0;
	bool a, p = 1;

	for (maxn i = 1; i <= n; i++) {
		p = !p;
		for (maxn j = 1; j <= n; j++) {
			std::cin >> a;

			s[p][j] = (a == W) * (std::min(s[!p][j], std::min(s[p][j - 1], s[!p][j - 1])) + 1);
			if (s[p][j] == res_size) ++res_cnt;
			else if (s[p][j] > res_size) res_size = s[p][j], res_cnt = 1;
		}
	}

	std::cout << res_size * res_cnt;
}


int main() {
	//freopen("timhinh.inp", "r", stdin);
	//freopen("timhinh.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}