#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 1002
#define X first
#define Y second

typedef int maxn;
typedef std::pair <maxn, maxn> e_t;

maxn n1, n2, K, f[maxN][maxN];
bool d[maxN][maxN];
std::vector <e_t> E;


void Prepare() {
	std::cin >> n1 >> n2 >> K;

	maxn x, y;
	for (maxn i = 0; i < K; i++) {
		std::cin >> x >> y;
		E.push_back(e_t(x, y));
	}
	while (std::cin >> x >> y && x)
		d[x][y] = 1;

	E.push_back(e_t(n1 + 1, n2 + 1));
	std::reverse(E.begin(), E.end());
}


void Process() {
	for (maxn x = 1, hiy = E.back().Y, lowy = 0; x <= n1; x++) {
		if (x < E.back().X) {
			f[x][lowy] = f[x - 1][lowy];
			for (maxn y = lowy + 1; y < hiy; y++)
				f[x][y] = std::max(f[x - 1][y - 1] + d[x][y], std::max(f[x][y - 1], f[x - 1][y]));
		}
		else {
			E.pop_back();
			lowy = hiy, hiy = E.back().Y;

			f[x][lowy] = f[x - 1][lowy - 1];
			for (maxn y = lowy + 1; y < hiy; y++)
				f[x][y] = f[x][y - 1];
		}
	}

	//for(maxn i = 1; i <= n1; i++) for(maxn j = 1; j <= n2; j++) std::cout << i << ' ' << j << ' ' << f[i][j] << '\n';

	std::cout << f[n1][n2];
}


int main() {
	//freopen("bridge.inp", "r", stdin);
	//freopen("bridge.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}