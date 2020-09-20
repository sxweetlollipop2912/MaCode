#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxD 32
#define maxM 13
#define win(d, m) (wM[m] == (d))

typedef int maxn;

maxn D, M, wD[maxD], wM[maxM];
bool inv[maxD][maxM];


void Prepare() {
	std::cin >> D >> M;

	inv[31][12] = inv[30][2] = inv[31][2] = inv[31][4] = inv[31][6] = inv[31][9] = inv[31][11] = 1;
}


void Process() {
	for (maxn m = 12; m >= 1; m--) for (maxn d = 31; d >= 1; d--) {
		if (inv[d][m]) continue;
		if (!wM[m] && !wD[d]) wM[m] = d, wD[d] = m;
	}
	
	if (!win(D, M) && wM[M] > D) std::cout << wM[M] << ' ' << M;
	else if (!win(D, M) && wD[D] > M) std::cout << D << ' ' << wD[D];
	else std::cout << "-1";
}


int main() {
	//freopen("g3112.inp", "r", stdin);
	//freopen("g3112.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}