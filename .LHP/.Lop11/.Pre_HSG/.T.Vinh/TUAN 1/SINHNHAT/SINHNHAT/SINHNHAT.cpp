#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 403
#define empty 0
#define block 1
#define cv(a, b) ((a)*2 + (b)*2)

typedef int maxn;

maxn r, c, s[maxN][maxN], res;
bool a[maxN][maxN];


void Prepare() {
	std::cin >> r >> c;

	for (maxn i = 1; i <= r; i++) {
		for (maxn j = 1; j <= c; j++) {
			char c;
			std::cin >> c;
			a[i][j] = c == '#';
		}
	}

	for (maxn i = r; i > 0; i--) {
		for (maxn j = 1; j <= c; j++) {
			s[i][j] = (a[i][j] == empty) * (s[i + 1][j] + 1);
		}
	}
}


maxn Best(const maxn row) {
	maxn re = 0;
	std::vector <maxn> de;
	s[row][0] = -2, s[row][c + 1] = s[row][0] + 1;
	de.push_back(0);

	for (maxn i = 1; i <= c + 1; i++) {
		while (s[row][de.back()] >= s[row][i]) {
			maxn l = de[de.size() - 2] + 1, r = i - 1;
			re = std::max(re, (s[row][de.back()] != 0) * cv(s[row][de.back()], r - l + 1));
			de.pop_back();
		}
		de.push_back(i);
	}

	return re;
}


void Process() {
	for (maxn row = 1; row <= r; row++) {
		res = std::max(res, Best(row));
	}
	std::cout << res - 1;
}


int main() {
	//freopen("sinhnhat.inp", "r", stdin);
	//freopen("sinhnhat.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}