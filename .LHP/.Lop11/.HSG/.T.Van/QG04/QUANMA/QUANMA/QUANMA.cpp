#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 201
#define x first
#define y second
#define win 0
#define lose 1
#define valid(xx, yy) ((xx) >= 0 && (xx) < m && (yy) >= 0 && (yy) < n)

typedef int maxn;
typedef std::pair <maxn, maxn> co_t;

maxn m, n, q, state[maxN][maxN], cnt[maxN][maxN], f[4][2] = { {1,-2},{-1,-2},{-2,-1},{-2,1} };


void Prepare() {
	std::cin >> m >> n >> q;

	for (maxn i = 0; i < m; i++) for (maxn j = 0; j < n; j++) for (int k = 0; k < 4; k++)
		if (valid(i + f[k][0], j + f[k][1])) ++cnt[i][j];
}


void Fill(std::vector <co_t>& st, const co_t u) {
	for (int k = 0; k < 4; k++) {
		maxn vx = u.x - f[k][0], vy = u.y - f[k][1];
		if (!valid(vx, vy)) continue;

		if (state[u.x][u.y] == win) state[vx][vy] = lose;
		if (!(--cnt[vx][vy])) st.push_back(co_t(vx, vy));
	}
}


void Process() {
	std::vector <co_t> st;

	state[0][0] = state[0][1] = state[1][0] = state[1][1] = win;
	st.push_back(co_t(0, 0)); st.push_back(co_t(0, 1));
	st.push_back(co_t(1, 0)); st.push_back(co_t(1, 1));

	while (!st.empty()) {
		co_t u = st.back(); st.pop_back();
		Fill(st, u);
	}

	while (q--) {
		maxn qx, qy; std::cin >> qx >> qy, --qx, --qy;
		if (state[qx][qy] == win) std::cout << "-1\n";
		else std::cout << "1\n";
	}
}


int main() {
	//freopen("quanma.inp", "r", stdin);
	//freopen("quanma.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}