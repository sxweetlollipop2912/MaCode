#include <iostream>
#include <algorithm>
#include <cstdio>
#include <unordered_map>

#define maxN 501
#define maxA 40001

typedef int maxn, maxa;
typedef std::pair <maxa, maxa> p_t;

maxn n[4];
maxa a[4][maxN];
std::unordered_map <maxa, p_t> map;


void Prepare() {
	std::cin >> n[0] >> n[1] >> n[2] >> n[3];
	for (int ii = 0; ii < 4; ii++) for (maxn i = 0; i < n[ii]; i++) std::cin >> a[ii][i];
}


void Process() {
	for (maxn i = 0; i < n[0]; i++) for (maxn j = 0; j < n[1]; j++) map[a[0][i] + a[1][j]] = p_t(a[0][i], a[1][j]);
	for (maxn i = 0; i < n[2]; i++) for (maxn j = 0; j < n[3]; j++) {
		maxa val = -(a[2][i] + a[3][j]);
		if (map.find(val) == map.end()) continue;
		std::cout << map[val].first << ' ' << map[val].second << ' ' << a[2][i] << ' ' << a[3][j];
		return;
	}
}


int main() {
	//freopen("zero.inp", "r", stdin);
	//freopen("zero.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}