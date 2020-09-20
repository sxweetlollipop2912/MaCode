// AC UVa
#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cstdio>
#include <cstring>

#pragma warning(disable:4996)

#define maxN 17
#define maxA 102
#define maxB ((1 << 15) + 1)

typedef int maxn, maxa, maxb;

maxn n;
maxa a[maxN], X, Y, S[maxB];
bool f[maxA][maxB], done[maxA][maxB];


void Prepare() {
	std::cin >> X >> Y;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];

	for (maxb b = 0; b < (1 << n); b++, S[b] = 0) for (maxn i = 0; i < n; i++)
		if ((b >> i) & 1) S[b] += a[i];
}


bool DP(const maxa x, const maxa y, const maxb b) {
	if (x > X || y > Y || x * y != S[b]) return 0;
	if (done[x][b]) return f[x][b];
	done[x][b] = done[y][b] = 1, f[x][b] = f[y][b] = 0;

	if (b - (b & (-b)) == 0) return (f[x][b] = f[y][b] = 1);

	for (maxb b1 = 1; b1 <= b / 2; b1++) {
		if (((b | b1) == b) && ((DP(x, S[b1] / x, b1) && DP(x, S[b - b1] / x, b - b1)) || (DP(S[b1] / y, y, b1) && DP(S[b - b1] / y, y, b - b1)))) 
			return (f[x][b] = f[y][b] = 1);
	}
	return (f[x][b] = f[y][b] = 0);
}


void Process() {
	memset(done, 0, sizeof(done));

	if (DP(X, Y, (1 << n) - 1)) std::cout << "Yes\n";
	else std::cout << "No\n";
}


int main() {
	//freopen("1099.inp", "r", stdin);
	//freopen("1099.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int cntq = 0;
	while (std::cin >> n && n) {
		++cntq, std::cout << "Case " << cntq << ": ";
		Prepare();
		Process();
	}
}