// undone, pending Result
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxD 20
#define D 18
#define maxS 164
#define S 162
#define maxN 11
#define N 9

typedef long long maxa;
typedef int maxs, maxd, maxn;

maxa n, res, pow[maxD];
maxd L;
maxs s;
maxn digit[maxN];
bool f[maxD][maxS][maxN];


void DP() {
	for (maxa s = 0; s <= S; s++) for (maxa n = 0; n <= N; n++)
		f[0][s][n] = 1;
	for (maxa d = 1; d <= D; d++) for (maxa s = 0; s <= S; s++) for (maxa n = 0; n <= N; n++) {
		f[d][s][n] = 0;
		if (n <= s)
			for (maxa n1 = 0; n1 <= N; n1++) f[d][s][n] |= f[d - 1][s - n][n1];
		if (s != 0)
			f[d][s][n] != f[n][s - 1][n];
	}
}


void Prepare() {
	std::cin >> n >> s;
	pow[1] = 1;
	for (maxd d = 1; d <= D; d++) pow[d] = pow[d - 1] * 10;

	L = 0;
	for (maxa a = n, i = 0; a != 0; a /= 10, i++) ++L, digit[i] = a % 10;
}


maxa Result(maxd d, maxs s, maxn curDigit = -1) {
	if (d == 0) return 0;
	if (curDigit != -1 && f[d][s][curDigit])
		return curDigit * pow[d] + Result(d - 1, s - curDigit, digit[d - 1]);

	for (maxn i = curDigit + 1; i <= N; i++)
		if (f[d][s][i])
			return i * pow[d] + Result(d - 1, s - i);
	return -1;
}


void Process() {
	res = -1;
	res = Result(L, s, digit[L - 1]);
}


int main() {
	DP();
	Prepare();
	Process();
}