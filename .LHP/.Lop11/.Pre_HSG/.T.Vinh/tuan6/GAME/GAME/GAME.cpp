#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define maxN 501
#define maxC 1000000005
#define x first
#define y second
#define U 0
#define D 1
#define R 2
#define L 3
#define done(x) ((bool)(mn[x] != maxC))

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> co_t, pair_t;

maxn n, CNT;
co_t co[maxN];
int dir[maxN];
bool id_dir[4] = { 0,0,1,1 };
std::vector <pair_t> pair;
maxa t[maxN][maxN], mn[maxN];


maxa time(maxn id1, maxn id2) {
	if (co[id1] == co[id2]) return 0;
	if (dir[id1] == dir[id2]) return maxC;

	if (co[id1].y < co[id2].y) std::swap(id1, id2);
	if (co[id1].y != co[id2].y && dir[id1] != D && dir[id2] != U) return maxC;

	if (co[id1].x < co[id2].x) std::swap(id1, id2);
	if (co[id1].x != co[id2].x && dir[id1] != L && dir[id2] != R) return maxC;

	if (id_dir[dir[id1]] != id_dir[dir[id2]] && abs(co[id1].x - co[id2].x) != abs(co[id1].y - co[id2].y)) return maxC;
	return abs(co[id1].x - co[id2].x) + abs(co[id1].y - co[id2].y);
}


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) {
		char c;
		std::cin >> co[i].x >> co[i].y >> c;
		dir[i] = c == 'U' ? U : c == 'D' ? D : c == 'L' ? L : R;
		for (maxn j = 0; j < i; j++) {
			t[i][j] = t[j][i] = time(i, j);
			if (t[i][j] != maxC) pair.push_back(pair_t(i, j));
		}
		mn[i] = maxC;
	}
}


bool cmp(const pair_t& p1, const pair_t& p2) {
	return t[p1.first][p1.second] < t[p2.first][p2.second];
}


void Process() {
	std::sort(pair.begin(), pair.end(), cmp);
	CNT = 0;

	for (maxn i = 0; i < pair.size(); i++) {
		maxn r1 = pair[i].first, r2 = pair[i].second;
		if (t[r1][r2] > mn[r1] || t[r1][r2] > mn[r2]) continue;
		CNT += !done(r1) + !done(r2);
		mn[r1] = mn[r2] = t[r1][r2];
	}
	if (CNT == n) std::cout << "No";
	else for (maxn i = 0; i < n; i++) if (!done(i)) std::cout << i + 1 << '\n';
}


int main() {
	//freopen("game.inp", "r", stdin);
	//freopen("game.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}