#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 10006
#define maxR 6
#define ROW 4
#define maxB 17

typedef int maxn, maxb;
typedef long long maxa;

maxn COL;
maxa a[maxR][maxN], f[maxN][maxB];


void Prepare() {
	std::cin >> COL;
	for (maxn i = 0; i < ROW; i++) for (maxn j = 1; j <= COL; j++) std::cin >> a[i][j];
}


void Process() {
	for (maxn c = 1; c <= COL; c++) for (maxb b = 0; b < (1 << ROW); b++) {
		for (maxn r = 0; r < std::min(ROW, c); r++) 
			f[c][b] += ((b >> r) & 1) * a[r][c - r];
		maxa t = f[c][b];
		for (maxb b1 = 0; b1 < (1 << ROW); b1++) {
			if ((b1 & b) || ((b1 << 1) & b)) continue;
			f[c][b] = std::max(f[c][b], t + f[c - 1][b1]);
		}
		//std::cout << c << ' ' << b << ' ' << t << ' ' << f[c][b] << '\n';
	}

	for (maxn r = 1, c = COL; r < ROW; r++) for (maxb b = 0; b < (1 << ROW); b++) {
		for (maxn rr = r; rr < ROW; rr++)
			f[c + r][b] += ((b >> rr) & 1) * a[rr][c + r - rr];
		maxa t = f[c + r][b];
		for (maxb b1 = 0; b1 < (1 << ROW); b1++) {
			if ((b1 & b) || ((b1 << 1) & b)) continue;
			f[c + r][b] = std::max(f[c + r][b], t + f[c + r - 1][b1]);
		}
		//std::cout << r << ' ' << b << ' ' << t << ' ' << f[c + r][b] << '\n';
	}
	std::cout << *std::max_element(f[COL + ROW - 1], f[COL + ROW - 1] + maxB);
}


int main() {
	//freopen("select.inp", "r", stdin);
	//freopen("select.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}