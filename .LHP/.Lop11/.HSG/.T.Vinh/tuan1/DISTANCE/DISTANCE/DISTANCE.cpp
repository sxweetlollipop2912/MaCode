// AC
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define maxN 1002
#define del 1
#define ins 1
#define rep 2

typedef int maxn;
typedef std::string str;

maxn n1, n2, f[maxN][maxN];
str s1, s2;


void Prepare() {
	std::cin >> s1 >> s2;
	n1 = s1.size(), n2 = s2.size();
}


void Process() {
	f[0][0] = 0;
	for (maxn i = 1; i <= n2; i++) f[0][i] = i;

	for (maxn i1 = 1; i1 <= n1; i1++) {
		f[i1][0] = f[i1 - 1][0] + del;
		for(maxn i2 = 1; i2 <= n2; i2++) {
			f[i1][i2] = std::min(f[i1 - 1][i2] + del, std::min(f[i1 - 1][i2 - 1] + (s1[i1 - 1] != s2[i2 - 1]) * rep, f[i1][i2 - 1] + ins));
			//std::cout << i1 << ' ' << i2 << ' ' << s1[i1 - 1] << ' ' << s2[i2 - 1] << ' ' << f[i1][i2] << '\n';
			//std::cout << "xoa " << f[i1 - 1][i2] + del  << '\n';
			//std::cout << "doi " << f[i1 - 1][i2 - 1] + (s1[i1 - 1] != s2[i2 - 1]) * rep << '\n';
			//std::cout << "them " << f[i1][i2 - 1] + ins << '\n';
		}
	}
	std::cout << f[n1][n2];
}


int main() {
	//freopen("distance.inp", "r", stdin);
	//freopen("distance.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}