#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define maxL 1002
#define maxN 51
#define maxR 1000001

typedef int maxn;
typedef long maxa;

maxn n;
maxa len, a[maxN], dp[maxL][maxL];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
	std::sort(a, a + n);
	memset(dp, -1, sizeof(dp));
}


maxa Top_Down(const maxn L, const maxn R) {
	if (dp[L][R] != -1) return dp[L][R];  dp[L][R] = maxR;

	for (maxn i = 0; i < n; i++) 
		if (L < a[i] && a[i] < R) dp[L][R] = std::min(dp[L][R], R - L + Top_Down(L, a[i]) + Top_Down(a[i], R));

	if (dp[L][R] == maxR) dp[L][R] = 0;
	//std::cout << L << ' ' << R << ' ' << dp[L][R] << '\n';
	return dp[L][R];
}


void Process() {
	std::cout << Top_Down(0, len) << '\n';
}


int main() {
	freopen("xego.inp", "r", stdin);
	freopen("xego.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> len && len) {
		Prepare();
		Process();
	}
}