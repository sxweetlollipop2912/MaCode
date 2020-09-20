#include <iostream>
#include <string>
#include <algorithm>

#define maxN 300002
#define a 1
#define b 2
#define c 3
#define fail 4
#define maxC 3
#define num(x) ((x) - 'a')

typedef long maxn;
typedef int maxa;
typedef std::string str;

maxn n;
bool g[maxC][maxC], f[maxN][maxC];


void Prepare() {
	str s, t;
	std::cin >> n >> s >> t;
	g[num(s[0])][num(s[1])] = g[num(t[0])][num(t[1])] = 1;
}


str Trace(maxa cur) {
	maxn i = 3 * n;
	str s;

	while (i >= 0) {
		s = (char)(cur + 'a' - 1) + s;
		cur = f[i][cur], --i;
	}
	return s;
}


void Process() {
	f[0][0] = f[0][1] = f[0][2] = 1;

	for (maxn i = 1; i <= n * 3; i++) {
		for (maxn j2 = 0; j2 < maxC; j2++) {
			f[i][j2] = fail;
			for (maxn j1 = 0; j1 < maxC; j1++) {
				if (f[i - 1][j1] == fail || g[j1][j2]) continue;
				f[i][j2] = j1;
				break;
			}
		}
	}

	if (f[3 * n][a] == fail && f[3 * n][b] == fail && f[3 * n][c] == fail) std::cout << "NO";
	else {
		std::cout << "YES\n";
		if (f[3 * n][a] != fail) std::cout << Trace(a);
		else if (f[3 * n][b] != fail) std::cout << Trace(b);
		else if (f[3 * n][c] != fail) std::cout << Trace(c);
	}
}


int main() {
	Prepare();
	Process();
}