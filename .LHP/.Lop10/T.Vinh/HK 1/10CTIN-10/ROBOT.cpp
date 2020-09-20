#include <iostream>
#include <fstream>
#include <queue>

std::queue <int> a[51];
bool f[51][51], mark[51][51], kt = true;
int check[51], step[51];
int m, n, k, p, cur_step;

void Prepare() {
	freopen("ROBOT.inp","r",stdin);
	freopen("ROBOT.out", "w", stdout);
	std::cin >> n >> m >> k >> p;
	for (int i = 0; i < p; i++) {
		int c;
		std::cin >> c;
		a[i].push(c - 1);
		check[c - 1]++;
		mark[i][c - 1] = 1;
	}
	for (int i = 0; i < m; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		f[u - 1][v - 1] = c;
		f[v - 1][u - 1] = c;
	}
	for (int i = 0; i < k; i++) {
		int c;
		std::cin >> c;
		check[c - 1] = -1;
	}
}

int Next(int ii) {
	int l = a[ii].size();
	kt = l > 0;
	while (l > 0) {
		int c = a[ii].front();
		a[ii].pop();
		for (int i = 0; i < n; i++)
			if ((check[i] != -1) && (f[c][i]) && (!mark[ii][i])) {
				a[ii].push(i);
				mark[ii][i] = 1;
				check[i]++;
				step[i] += cur_step;
				if (check[i] == p) return step[i];
			}
		l--;
	}
	return -1;
}

int main() {
	Prepare();
	while (kt) {
		kt = false;
		cur_step++;
		for (int i = 0; i < p; i++) {
			int re = Next(i);
			if (re == -1) continue;
			std::cout << re;
			return 0;
		}
	}
}
