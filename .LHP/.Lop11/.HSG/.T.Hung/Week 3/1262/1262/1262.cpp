// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define ROW 6
#define COL 5
#define maxN 7
#define maxC 27
#define num(c) ((c) - 'A')

typedef int maxn, maxa;
typedef std::string str;

bool a[maxN][maxC], b[maxN][maxC];
maxn CNT, K;
str res;


void Init() {
	for (maxn i = 0; i < COL; i++) {
		std::fill(a[i], a[i] + maxC, 0);
		std::fill(b[i], b[i] + maxC, 0);
	}
	CNT = 0, res = "";
}


void Prepare() {
	std::cin >> K;
	for (maxn i = 0; i < ROW; i++) for (maxn j = 0; j < COL; j++) {
		char c; std::cin >> c;
		a[j][num(c)] = 1;
	}
	for (maxn i = 0; i < ROW; i++) for (maxn j = 0; j < COL; j++) {
		char c; std::cin >> c;
		b[j][num(c)] = 1;
	}
}


void Try(const maxn col, str s) {
	if (CNT == K) return;
	if (col == COL) res = s, ++CNT;
	else 
	for (char c = 'A'; c <= 'Z'; c++) {
		if (!a[col][num(c)] || !b[col][num(c)]) continue;
		Try(col + 1, s + c);
	}
}


void Process() {
	Try(0, "");
	if (CNT == K) std::cout << res << '\n';
	else std::cout << "NO\n";
}


int main() {
	//freopen("1262.inp", "r", stdin);
	//freopen("1262.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q; std::cin >> q;

	while (q--) {
		Init();
		Prepare();
		Process();
	}
}