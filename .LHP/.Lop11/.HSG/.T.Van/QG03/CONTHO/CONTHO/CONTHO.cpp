#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 3001
#define none 0
#define part 1
#define both 2
#define bef 0
#define aft 1

typedef int maxn;
typedef long maxa;

maxn n;
maxa cost[maxN][3], f[maxN][2];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> cost[i][none];
	for (maxn i = 0; i < n; i++) std::cin >> cost[i][part];
	for (maxn i = 0; i < n; i++) std::cin >> cost[i][both];
}


void Process() {
	f[0][bef] = cost[0][none], f[0][aft] = cost[0][part];

	for (maxn i = 1; i < n - 1; i++) {
		f[i][bef] = std::max(f[i - 1][bef] + cost[i][part], f[i - 1][aft] + cost[i][none]);
		f[i][aft] = std::max(f[i - 1][bef] + cost[i][both], f[i - 1][aft] + cost[i][part]);
	}
	std::cout << std::max(f[n - 2][bef] + cost[n - 1][part], f[n - 2][aft] + cost[n - 1][none]);
}


int main() {
	//freopen("contho.inp", "r", stdin);
	//freopen("contho.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}