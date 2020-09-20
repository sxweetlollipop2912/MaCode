#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

#pragma warning (disable:4996)

#define maxN 1301
#define x first
#define y second
#define cor first
#define len second

typedef int maxn;
typedef std::pair <maxn, maxn> co;
typedef std::pair <co, maxn> info;

maxn row, col, res;
bool a[maxN][maxN];


void Prepare() {
	std::cin >> row >> col;

	for (maxn i = 0; i < row; i++) {
		for (maxn j = 0; j < col; j++) {
			char c;
			std::cin >> c;
			a[i][j] = c == '1';
		}
	}
}


bool Check(const co c, const maxn size) {
	if (c.x < 0 || c.y < 0 || size > std::min(row - c.x, col - c.y)) return 0;

	for (maxn s = 0; s < size; s++) {
		if (a[c.x][c.y + s] != a[c.x + size - 1][c.y + size - 1 - s]) return 0;
	}
	for (maxn s = 0; s < size; s++) {
		if (a[c.x + s][c.y] != a[c.x + size - 1 - s][c.y + size - 1]) return 0;
	}
	return 1;
}


void Process(bool s) {
	std::queue <info> re;

	for (maxn i = 0; i < row; i++) {
		for (maxn j = 0; j < col; j++) {
			co c = co(i, j);
			if (Check(c, 1 + s)) re.push(info(c, 1 + s));
		}
	}

	while (!re.empty()) {
		res = std::max(res, re.front().len);
		co c = re.front().cor;
		--c.x, --c.y;
		if (Check(c, re.front().len + 2)) re.push(info(c, re.front().len + 2));
		re.pop();
	}
}


int main() {
	//freopen("hvdx.inp", "r", stdin);
	//freopen("hvdx.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process(0);
	Process(1);

	if (res <= 1) res = -1;
	std::cout << res;
}