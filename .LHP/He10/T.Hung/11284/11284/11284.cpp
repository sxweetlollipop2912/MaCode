// AC UVa
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <string>

#pragma warning(disable:4996)

#define maxN 52
#define maxM 1001
#define maxP 13
#define Scena 8192
#define maxR 999999999
#define minR -maxR
#define none -1

typedef int maxn, maxm;
typedef unsigned int scena;
typedef long long maxa;
typedef std::string str;

maxn n, P;
maxm m;
maxa c[maxN][maxN], f[maxP][Scena], save[maxN], res;
std::vector <maxn> p;


void Init() {
	for (maxn i = 0; i < maxN; i++) std::fill(c[i], c[i] + maxN, minR);
	for (maxn i = 0; i < maxP; i++) std::fill(f[i], f[i] + Scena, none);
	std::fill(save, save + maxN, 0);
	c[0][0] = 0;
	p.clear();
	p.push_back(0);
}


maxa Str2Num(const str &s) {
	maxa re = s[0] - '0';
	for (int i = 1; i < s.size(); i++)
		if (s[i] != '.') re = re * 10 + (s[i] - '0');
	return re;
}


void Prepare() {
	std::cin >> n >> m;
	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		str a;
		std::cin >> u >> v >> a;
		c[u][v] = c[v][u] = std::max(c[u][v], -Str2Num(a));
	}

	std::cin >> P;
	std::vector <bool> isP(n + 1, 0);
	for (maxn i = 0; i < P; i++) {
		maxn v;
		str a;
		std::cin >> v >> a;
		save[v] += Str2Num(a);

		if (isP[v]) continue;
		isP[v] = 1;
		p.push_back(v);
	}
}


void Floyd() {
	for (maxn k = 0; k <= n; k++) 
		for (maxn i = 0; i <= n; i++) 
			for (maxn j = 0; j <= n; j++) 
				c[i][j] = std::max(c[i][j], c[i][k] + c[k][j]);
}


scena visit(const scena a, const maxn p) {
	return a | (1 << p);
}

bool visited(const scena a, const maxn p) {
	return a & (1 << p);
}


maxa Try(const maxn id, const scena a) {
	if (f[id][a] != none) return f[id][a];
	maxn u = p[id];
	f[id][a] = c[u][0];

	for (maxn i = 1; i < p.size(); i++) {
		maxn v = p[i];
		if (visited(a, i)) continue;
		f[id][a] = std::max(f[id][a], c[u][v] + save[v] + Try(i, visit(a, i)));
	}

	return f[id][a];
}


void Process() {
	Floyd();
	res = Try(0, 0);
	if (!res) std::cout << "Don't leave the house\n";
	else std::cout << "Daniel can save $" << res / (double)100 << '\n';
}


int main() {
	//freopen("11284.inp", "r", stdin);
	//freopen("11284.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	int q;
	std::cin >> q;

	while (q--) {
		Init();
		Prepare();
		Process();
	}
}