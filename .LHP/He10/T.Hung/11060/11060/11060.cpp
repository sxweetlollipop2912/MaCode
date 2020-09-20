#include"pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

#define maxN 101
#define maxM 201

typedef int maxn, maxm;
typedef std::string str;

maxn n;
maxm m;
str b[maxN];
std::vector <maxn> ad[maxN];
bool done[maxN];
int cntq;


void Init() {
	for (maxn i = 0; i < n; i++) ad[i].clear();
	std::fill(done, done + n, 0);
}


void Prepare() {
	std::map <str, maxn> id;

	for (maxn i = 0; i < n; i++) {
		std::cin >> b[i];
		id[b[i]] = i;
	}

	std::cin >> m;
	for (maxm i = 0; i < m; i++) {
		str u, v;
		std::cin >> u >> v;
		ad[id[v]].push_back(id[u]);
	}
}


void DFS(const maxn ID) {
	done[ID] = 1;

	for (maxn i = 0; i < ad[ID].size(); i++) {
		if (!done[ad[ID][i]]) DFS(ad[ID][i]);
	}

	std::cout << ' ' << b[ID];
}


void Process() {
	std::cout << "Case #" << cntq << ": Dilbert should drink beverages in this order:";

	for (maxn i = 0; i < n; i++)
		if (!done[i]) DFS(i);
	
	std::cout << ".\n\n";
}


int main() {
	//freopen("11060.inp", "r", stdin);
	//freopen("11060.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	cntq = 0;
	while (std::cin >> n) {
		++cntq;
		Init();
		Prepare();
		Process();
	}
}