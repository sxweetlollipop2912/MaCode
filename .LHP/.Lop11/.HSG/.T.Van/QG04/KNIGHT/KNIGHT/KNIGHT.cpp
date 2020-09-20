#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>

//#define maxN 100001
//#define maxA 1000000001
#define x first
#define y second

typedef long maxn, maxa;
typedef std::pair <maxa, maxa> co_t;

co_t st, en;
maxa f[8][2] = { {-2,-1},{-2,1},{-1,-2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2} };
std::set <co_t> set;
std::queue <co_t> bfs;


void Prepare() {
	std::cin >> st.x >> st.y >> en.x >> en.y;

	maxn n = 0; std::cin >> n;
	while (n--) {
		maxn r, a, b; std::cin >> r >> a >> b;
		for (maxa i = a; i <= b; i++) set.insert(co_t(r, i));
	}
}


maxn BFS(const co_t st, const co_t en) {
	maxn step = 0;
	bfs.push(st); set.erase(st);

	while (!bfs.empty()) {
		maxn len = bfs.size(); ++step;
		while (len--) {
			co_t u = bfs.front(); bfs.pop();

			for (int k = 0; k < 8; k++) {
				co_t v;
				v.x = u.x + f[k][0], v.y = u.y + f[k][1];
				if (set.find(v) == set.end()) continue;

				if (v == en) return step;
				bfs.push(v); set.erase(v);
			}
		}
	}
	return -1;
}


void Process() {
	std::cout << BFS(st, en);
}


int main() {
	//.freopen("knight.inp", "r", stdin);
	//freopen("knight.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}