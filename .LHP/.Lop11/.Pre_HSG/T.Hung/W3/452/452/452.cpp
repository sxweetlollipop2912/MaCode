// PE UVa
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>

#define maxN 100

typedef int maxn;
typedef char maxa;
typedef long maxc;
typedef std::string str;

maxn n;
maxc C[maxN], Cmax[maxN], res;
std::vector <maxa> exist, deg0;
bool g[maxN][maxN], done[maxN];
str input;


void Init() {
	exist.clear();
	deg0.clear();
	memset(g, 0, sizeof(g));
}


void Prepare() {
	while (getline(std::cin, input) && input != "") {
		std::stringstream ss(input);
		char c; maxn cost; str c1;
		
		ss >> c >> cost >> c1;
		exist.push_back(c);
		C[c] = cost;
		if (c1.size() == 0) deg0.push_back(c);
		for (maxn i = 0; i < c1.size(); i++) g[c1[i]][c] = 1;
	}
}


maxc DFS(const maxa u) {
	if (done[u]) return Cmax[u];

	done[u] = 1, Cmax[u] = C[u];

	for (maxn i = 0; i < exist.size(); i++) {
		maxa v = exist[i];
		if (g[u][v]) Cmax[u] = std::max(Cmax[u], C[u] + DFS(v));
	}
	return Cmax[u];
}


void Process() {
	res = 0;
	memset(done, 0, sizeof(done));
	for (maxn i = 0; i < deg0.size(); i++) res = std::max(res, DFS(deg0[i]));
	std::cout << res << "\n\n";
}


int main() {
	std::ios_base::sync_with_stdio(0);

	int q;
	std::cin >> q;

	std::cin.ignore();
	std::getline(std::cin, input);

	while (q--) {
		Init();
		Prepare();
		Process();
	}
}