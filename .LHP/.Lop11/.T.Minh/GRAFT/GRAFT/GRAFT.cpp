#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

#define maxN 20002

typedef int maxn;
typedef std::string str;

maxn n, par[maxN], f1[maxN], f2[maxN];
std::vector <maxn> ad[maxN];
str s;


void Prepare() {
	std::fill(f1, f1 + maxN, 0);
	std::fill(f2, f2 + maxN, 0);

	maxn cur = 0;  n = 1;
	ad[cur].clear();

	for (maxn i = 0; i < s.size(); i++) {
		if (s[i] == 'd') {
			par[n] = cur, f1[n] = f1[cur] + 1;
			ad[cur].push_back(n);
			cur = n++;
			ad[cur].clear();
		}
		else cur = par[cur];
	}
}


void DFS(const maxn u) {
	maxn fcnt = f2[u];
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		f2[v] = ++fcnt;
		DFS(v);
	}
}


void Process() {
	f2[0] = 0;
	DFS(0);
	std::cout << *std::max_element(f1, f1 + maxN) << ' ' << *std::max_element(f2, f2 + maxN) << '\n';
}


int main() {
	//freopen("graft.inp", "r", stdin);
	//freopen("graft.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> s && s != "#") {
		Prepare();
		Process();
	}
}