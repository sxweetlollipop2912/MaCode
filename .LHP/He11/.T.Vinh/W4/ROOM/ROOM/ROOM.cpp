// V - E + R = 1
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <string>

//#define maxN 200001
#define X first
#define Y second

typedef long maxn;
typedef std::pair <maxn, maxn> co_t, e_t;

maxn n, f[8][2] = { { -1, 0 },{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 } }, E, V;
std::string s;
std::map <co_t, maxn> map;
std::set <e_t> set;


void Prepare() {
	std::cin >> n >> s;
}


void Process() {
	co_t u = co_t(0, 0); map[u] = 0;
	V = 1, E = 0;

	for (maxn i = 0; i < n; i++) for (int k = 0; k < 2; k++) {
		int dir = s[i] - '0';
		co_t v = co_t(u.X + f[dir][0], u.Y + f[dir][1]);

		if (map.find(v) == map.end())
			map[v] = V++;

		e_t e = e_t(std::min(map[u], map[v]), std::max(map[u], map[v]));
		if (set.find(e) == set.end())
			set.insert(e); ++E;

		u = v;
	}

	std::cout << E - V + 1;
}


int main() {
	freopen("room.inp", "r", stdin);
	freopen("room.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}