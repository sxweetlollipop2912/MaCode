// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <sstream>

#define maxN 31
#define maxA 6003
#define index(a) ((a) + 3000)
#define add 0
#define sub 1
#define ex(p) ((p == add) ? 1 : -1)

typedef int maxn, maxa;
typedef std::string str;

maxn n;
maxa a[maxN], res;
bool done[maxN][maxN][maxA], made[maxA];
int expr[maxN];
str s;


void Init() {
	res = 0;
	for (maxa i = 0; i < maxA; i++) {
		made[i] = 0;
		for (maxn j = 0; j < maxN; j++) for (maxn k = 0; k < maxN; k++) done[j][k][i] = 0;
	}
}


void Prepare() {
	maxa x; char c;
	std::stringstream ss(s);
	n = 0;
	ss >> a[n++];
	while (ss >> c >> a[n]) expr[n - 1] = c == '+' ? add : sub, ++n;
}


void DP(const maxn i, const maxn open, const maxa val) {
	if (done[i][open][index(val)]) return;
	done[i][open][index(val)] = 1;
	if (i == n) {
		res += !made[index(val)], made[index(val)] = 1;
		return;
	}
	DP(i + 1, open, val + a[i] * ex(expr[i - 1] ^ (open & 1)));

	if (expr[i - 1] == sub) DP(i + 1, open + 1, val + a[i] * ex(expr[i - 1] ^ (open & 1)));
	if (open != 0)          DP(i + 1, open - 1, val + a[i] * ex(expr[i - 1] ^ (open & 1)));
}


void Process() {
	DP(1, 0, a[0]);
	std::cout << res << '\n';
}


int main() {
	//freopen("1238.inp", "r", stdin);
	//freopen("1238.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::getline(std::cin, s)) {
		Init();
		Prepare();
		Process();
	}
}