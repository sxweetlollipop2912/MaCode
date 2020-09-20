#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>

//#define maxMN 101
#define maxN 203
#define N (B + P + 2)
#define delta 1
#define start 0
#define des N - 1
#define get_p(x) ((x) + B)

typedef int maxn, maxa;
typedef std::string str;

maxn B, P, trace[maxN];
maxa c[maxN][maxN];
maxn f[maxN][maxN];


void Prepare() {
	std::cin >> B >> P;

	str s;
	std::getline(std::cin, s);
	//std::cin.ignore();

	for (maxn b = 1; b <= B; b++) {
		std::getline(std::cin, s);
		std::stringstream ss;
		ss << s;
		maxn p;
		while (ss >> p) c[b][get_p(p)] = 1;
		c[start][b] = 1;
	}
}


bool Path() {
	std::queue <maxn> bfs;
	bfs.push(start);

	std::fill(trace, trace + N, -1);
	trace[start] = start;

	while (!bfs.empty()) {
		maxn u = bfs.front();
		bfs.pop();

		for (maxn v = 0; v < N; v++) {
			if (trace[v] != -1 || c[u][v] == f[u][v]) continue;
			trace[v] = u;

			if (v == des) return 1;
			bfs.push(v);
		}
	}

	return 0;
}


void Update() {
	maxn v, u = des;

	while (u != start) {
		v = u;
		u = trace[v];
		f[u][v] += delta;
		f[v][u] -= delta;
	}
}


bool Check(const maxn lim) {
	for (maxn p = get_p(1); p <= get_p(P); p++)
		c[p][des] = lim;

	for (maxn i = 0; i < N; i++) std::fill(f[i], f[i] + N, 0);
	while (Path()) Update();

	maxn re = 0;
	for (maxn p = get_p(1); p <= get_p(P); p++)
		re += std::max(f[p][des], 0);

	return re == B;
}


void Process() {
	maxn l = 0, r = B;

	while (l != r) {
		maxn m = (l + r) / 2;
		if (Check(m)) r = m;
		else l = m + 1;
	}

	std::cout << l << '\n';
	
	Check(l);
	for (maxn b = 1; b <= B; b++) for (maxn p = 1; p <= P; p++) if (f[b][get_p(p)] == 1) std::cout << p << ' ';
}


int main() {
	//freopen("seminar1a.inp", "r", stdin);
	//freopen("seminar1a.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}