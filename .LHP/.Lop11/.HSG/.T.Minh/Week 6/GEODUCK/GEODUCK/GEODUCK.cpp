#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 102
//#define maxT 1001
//#define maxE 1001
//#define maxL 2001
#define maxR 1003
#define X first
#define Y second
#define S 0
#define M 1
#define meet(tu, tv, d) ((((d) - (tv) + (tu)) / (double)2) + (tv))

typedef int maxn, maxm;
typedef double maxa;
typedef std::pair <maxn, maxn> e_t;

maxn n, N[2], G, r[2][maxR];
maxm m;
maxa Time, d[maxN][maxN];
bool duck[maxN], pass[2][maxN][maxN], fin[2];
std::vector <e_t> e;
std::vector <maxa> T[2][maxN];


void Prepare() {
	std::cin >> n >> m >> N[S] >> N[M] >> G >> Time;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa a;
		std::cin >> u >> v, --u, --v;
		std::cin >> d[u][v], d[v][u] = d[u][v];
		e.push_back(e_t(u, v));
	}

	for (maxn i = 0; i < N[S]; i++) std::cin >> r[S][i], --r[S][i];
	for (maxn i = 0; i < N[M]; i++) std::cin >> r[M][i], --r[M][i];
	for (maxn i = 0, x; i < G; i++) std::cin >> x, --x, duck[x] = 1;

	for (int p = 0; p <= 1; p++) for (maxn i = 1; i < N[p]; i++) {
		maxn x = r[p][i - 1], y = r[p][i];
		pass[p][x][y] = pass[p][y][x] = 1;
	}
}


bool Process() {
	for (int p = 0; p <= 1; p++) {
		maxa t = 0; maxn i;
		for (i = 0; i < N[p] && !duck[r[p][i]] && t <= Time; i++) {
			maxn u = r[p][i], v = r[p][i + 1];
			T[p][u].push_back(t); t += d[u][v];
		}
		fin[p] = i == N[p];
	}

	for (maxn i = 0; i < n; i++) for (maxn iS = 0, iM = 0; iS < T[S][i].size() && iM < T[M][i].size(); iS++) {
		while (iM < T[M][i].size() && T[M][i][iM] < T[S][i][iS]) ++iM;
		if (iM < T[M][i].size() && T[S][i][iS] == T[M][i][iM]) return 1;
	}
	for (int p = 0; p <= 1; p++) {
		maxn x = r[p][N[p] - 1];
		if (fin[p] && std::lower_bound(T[!p][x].begin(), T[!p][x].end(), T[p][x].back()) != T[!p][x].end()) return 1;
	}

	for (maxm i = 0; i < m; i++) {
		maxn x = e[i].X, y = e[i].Y; if (!pass[S][x][y] || !pass[M][x][y]) continue;

		for(int p = 0; p <= 1; p++) for (maxn iN = 0; iN < T[p][x].size(); iN++) {
			maxn it = std::upper_bound(T[!p][y].begin(), T[!p][y].end(), T[p][x][iN] - d[x][y]) - T[!p][y].begin();
			if (it == T[!p][y].size()) break;
			if (T[!p][y][it] < T[p][x][iN] + d[x][y] && meet(T[!p][y][it], T[p][x][iN], d[x][y]) <= Time) {
				//std::cout << meet(T[!p][y][it], T[p][x][iN], d[x][y]);
				return 1;
			}
		}
	}

	std::cout << "NO"; return 0;
}


int main() {
	//freopen("geoducks.inp", "r", stdin);
	//freopen("geoducks.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (Process()) std::cout << "YES";
}