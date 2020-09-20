#include <iostream>
#include <algorithm>
#include <queue>

#define maxN 701
#define maxA 1000001
#define fi first
#define se second
#define x first
#define y second
#define up 0
#define left 1
#define right 2
#define down 3
#define none -1
#define all -2

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> tim_t;
typedef std::pair <maxn, maxn> co;

maxn n, f[4][2] = { {-1,0},{0,-1},{0,1},{1,0} }, res;
maxa h[maxN][maxN], g[maxN][maxN];
bool done[maxN][maxN][4], ldone[maxN][maxN];
int reg[4] = { down,right,left,up };


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		for (maxn j = 0; j < n; j++) {
			std::cin >> h[i][j];
		}
	}

	for (maxn i = 0; i < n; i++) {
		for (maxn j = 0; j < n; j++) {
			std::cin >> g[i][j];
		}
	}
}


maxa gcd(maxa a, maxa b) {
	while (b != 0) {
		maxa tmp = a % b;
		a = b, b = tmp;
	}
	return a;
}


tim_t time(const co ca, const co cb) {
	maxa a = h[cb.x][cb.y] - h[ca.x][ca.y], b = g[ca.x][ca.y] - g[cb.x][cb.y], g = gcd(abs(a), abs(b));
	return !a ? !b ? tim_t(all, all) : tim_t(0, 0) : a * b <= 0? tim_t(none, none) : tim_t(abs(a) / g, abs(b) / g);
}


bool validCo(const co c) {
	return c.x >= 0 && c.x < n && c.y >= 0 && c.y < n;
}

bool noneTime(const tim_t time) {
	return time.fi == none && time.se == none;
}

bool allTime(const tim_t time) {
	return time.fi == all && time.se == all;
}

bool equalTime(const tim_t t1, const tim_t t2) {
	return !noneTime(t1) && !noneTime(t2) && (allTime(t1) || allTime(t2) || t1 == t2);
}


maxn BFS(co st, const tim_t req) {
	for (maxn i = 0; i < n; i++) 
		std::fill(ldone[i], ldone[i] + n, 0);

	std::queue <co> bfs;
	maxn re = 0;

	bfs.push(st);
	ldone[st.x][st.y] = 1;

	while (!bfs.empty()) {
		co cur = bfs.front();
		++re;
		bfs.pop();

		for (int i = 0; i < 4; i++) {
			co ncur = co(cur.x + f[i][0], cur.y + f[i][1]);
			if (!validCo(ncur)) continue;

			if (done[cur.x][cur.y][i]) {
				done[ncur.x][ncur.y][reg[i]] = 1;
				ldone[ncur.x][ncur.y] = 1;
				continue;
			}
			done[cur.x][cur.y][i] = 1;

			if (!ldone[ncur.x][ncur.y]) {
				ldone[ncur.x][ncur.y] = 1;
				tim_t t = time(st, ncur);
				if (equalTime(t, req)) bfs.push(ncur);
			}
			done[ncur.x][ncur.y][reg[i]] = 1;
		}
	}

	return re;
}


void Process() {
	res = 1;

	for (maxn i = 0; i < n; i++) {
		for (maxn j = 0; j < n; j++) {
			co cur = co(i, j);
			for (int k = 0; k < 4; k++) {
				if (done[i][j][k]) continue;

				co ncur = co(cur.x + f[k][0], cur.y + f[k][1]);
				if (!validCo(ncur)) continue;

				tim_t req = time(cur, ncur);
				if (noneTime(req)) continue;

				res = std::max(BFS(cur, req), res);
			}
		}
	}

	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}