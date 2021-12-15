//97/100
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
#include <vector>
#include <iterator>

#define maxN 302
#define MID ((m * n) / 2)

typedef int maxn;
typedef std::string str;
typedef std::vector <maxn> dp_t;

maxn m, n, res;
str map[2];
dp_t f[2][maxN];
bool cur, prev;


void Prepare() {
	std::cin >> m >> n;
}


maxn better(maxn x, maxn y) {
	maxn S = m * n;
	return abs(S - 2 * x) > abs(S - 2 * y) ? y : x;
}


bool up(maxn i, maxn j) {
	if (i == 0) return 0;
	if (j == 0 || j == n) return 1;
	return map[(i - 1) & 1][j - 1] != map[(i - 1) & 1][j];
}
bool left(maxn i, maxn j) {
	if (j == 0) return 0;
	if (i == 0 || i == m) return 1;
	return map[(i - 1) & 1][j - 1] != map[i & 1][j - 1];
}
bool right(maxn i, maxn j) {
	if (j == n) return 0;
	if (i == 0 || i == m) return 1;
	return map[(i - 1) & 1][j] != map[i & 1][j];
}


void Process() {
	for (maxn j = 0; j <= n; j++) {
		f[0 & 1][j].push_back(0);
	}

	std::cin >> map[0 & 1];

	for (maxn i = 1; i <= m; i++){
		cur = i & 1, prev = (i - 1) & 1;
		if (i != m) std::cin >> map[cur];

		for (maxn j = 0; j <= n; j++) {
			if (left(i, j))
				f[cur][j] = f[cur][j - 1];

			if (up(i, j)) {
				for (maxn k = 0; k < f[prev][j].size(); k++)
					f[prev][j][k] += j;
				for (maxn k = f[prev][j].size() - 2; k >= 0 && f[prev][j][k] > MID; k--)
					f[prev][j].pop_back();

				dp_t v = f[cur][j];
				f[cur][j].clear();
				std::set_union(v.begin(), v.end(), f[prev][j].begin(), f[prev][j].end(), std::back_inserter(f[cur][j]));
			}
			f[prev][j].clear();
		}
		
		for (maxn j = n; j >= 0; j--) {
			if (right(i, j)) {
				dp_t v = f[cur][j];
				f[cur][j].clear();
				std::set_union(v.begin(), v.end(), f[cur][j + 1].begin(), f[cur][j + 1].end(), std::back_inserter(f[cur][j]));
			}
		}
	}
	res = -maxN;
	for (maxn j = 0; j <= n; j++)
		for (auto k = f[(m) & 1][j].begin(); k != f[(m) & 1][j].end(); k++)
			res = better(res, *k);

	//std::cout << res << '\n';
	std::cout << abs((n * m) - (2 * res));
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}