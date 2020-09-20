#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>

#define maxN 203
#define INF 999999999
#define N (B + P + 2)
#define st 0
#define en (N - 1)
#define getB(x) (x)
#define getP(x) ((x) + B)

typedef int maxn, maxa;
typedef std::string str;

maxn B, P, trace[maxN];
maxa c[maxN][maxN], f[maxN][maxN], r;


void Prepare() {
	std::cin >> B >> P;

	str s;
	std::getline(std::cin, s);
	//std::cin.ignore();

	for (maxn b = 1; b <= B; b++) {
		std::cin >> c[st][getB(b)], r += c[st][getB(b)];

		std::getline(std::cin, s);
		std::stringstream ss;
		ss << s;
		maxn p;
		while (ss >> p) c[getB(b)][getP(p)] = INF;
	}
}


bool Path() {
	std::queue <maxn> bfs;
	bfs.push(st);

	std::fill(trace, trace + N, -1);
	trace[st] = st;

	while (!bfs.empty()) {
		maxn u = bfs.front();
		bfs.pop();

		for (maxn v = 0; v < N; v++) {
			if (trace[v] != -1 || c[u][v] == f[u][v]) continue;
			trace[v] = u;

			if (v == en) return 1;
			bfs.push(v);
		}
	}

	return 0;
}


void Update() {
	maxa delta = INF; maxn v, u = en;

	while (u != st) {
		v = u, u = trace[v];
		delta = std::min(delta, c[u][v] - f[u][v]);
	}

	v, u = en;
	while (u != st) {
		v = u, u = trace[v];
		f[u][v] += delta;
		f[v][u] -= delta;
	}
}


bool Check(const maxa lim) {
	for (maxn p = 1; p <= P; p++)
		c[getP(p)][en] = lim;

	for (maxn i = 0; i < N; i++) std::fill(f[i], f[i] + N, 0);
	while (Path()) Update();

	for (maxn b = 1; b <= B; b++)
		if (c[st][getB(b)] > 0 && c[st][getB(b)] != f[st][getB(b)]) return 0;

	return 1;
}


void Process() {
	maxa l = 0;

	while (l != r) {
		maxn m = (l + r) / 2;
		if (Check(m)) r = m;
		else l = m + 1;
	}

	std::cout << l << '\n';
	Check(l);
	for (maxn b = 1; b <= B; b++) {
		for (maxn p = 1; p <= P; p++) for (maxn i = 0; i < f[getB(b)][getP(p)]; i++) std::cout << p << ' ';
		std::cout << '\n';
	}
}


int main() {
	//freopen("seminar2a.inp", "r", stdin);
	//freopen("seminar2a.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}