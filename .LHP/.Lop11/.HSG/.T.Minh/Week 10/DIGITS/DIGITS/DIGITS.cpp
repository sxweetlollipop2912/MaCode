#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define maxN 62
#define N 60
#define shl(k) ((maxk)1 << (maxk)(k))

typedef int maxn;
typedef long long maxk;
typedef std::string str;

char a, b;
maxk K;
str res;


void Prepare() {
	if (a > b) std::swap(a, b);
}


void Process() {
	res = "";

	if (a == '0') {
		if (K == 1) res = a; else res = b;
		K -= 2;
	}

	for (maxn i = N; i >= 1 && K > 0; i--) {
		if (i != 1 && K < shl(i) - 1) continue;
		if (K <= shl(i) + shl(i - (maxk)1) - 2) res += a, K -= shl(i - (maxk)1);
		else res += b, K -= shl(i);
	}
	std::cout << res << '\n';
}


int main() {
	//freopen("digits.inp", "r", stdin);
	//freopen("digits.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> a >> b >> K) {
		Prepare();
		Process();
	}
}