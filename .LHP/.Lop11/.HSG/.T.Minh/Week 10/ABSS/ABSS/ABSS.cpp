#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>

#define maxN 1000002
#define maxA 2000002
#define idx(x) ((x) + 1000000)

typedef long maxn;
typedef std::string str;

maxn n, a[maxN], sum[maxN], pos[maxA], res;
str s;


void Prepare() {
	n = s.size();

	for (maxn i = 1; i <= n; i++) a[i] = s[i - 1] == 'A' ? 1 : -1, sum[i] = 0;
	memset(pos, 0, sizeof(pos));
}


void Process() {
	res = 0;
	for (maxn i = 1; i <= n; i++) {
		sum[i] = a[i] + sum[i - 1];
		if (!sum[i] || abs(sum[i]) == 1) res = i;
		if (pos[idx(sum[i])]) res = std::max(res, i - pos[idx(sum[i])]);
		else pos[idx(sum[i])] = i;

		if (pos[idx(sum[i] - 1)]) res = std::max(res, i - pos[idx(sum[i] - 1)]);
		if (pos[idx(sum[i] + 1)]) res = std::max(res, i - pos[idx(sum[i] + 1)]);
	}
	std::cout << res << '\n';
}


int main() {
	//freopen("abss.inp", "r", stdin);
	//freopen("abss.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> s) {
		Prepare();
		Process();
	}
}