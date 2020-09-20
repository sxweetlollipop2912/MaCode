#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_map>

#define maxN 51

typedef int maxn;
typedef std::string str;

maxn n, m, g[maxN][maxN], res;
std::unordered_map <str, maxn> map;


void push(const str& s, maxn& cnt) {
	if (map.find(s) != map.end()) return;
	map[s] = cnt++;
}


void Prepare() {
	for (maxn i = 0; i < n; i++) std::fill(g[i], g[i] + n, maxN);
	map.clear();

	for (maxn i = 0, cnt = 0; i < m; i++) {
		str s1, s2; std::cin >> s1 >> s2;
		push(s1, cnt); push(s2, cnt);
		g[map[s1]][map[s2]] = g[map[s2]][map[s1]] = 1;
	}
}


void Process() {
	for (maxn k = 0; k < n; k++) for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++)
		g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);

	res = 0;
	for (maxn u = 0; u < n; u++) for (maxn v = u + 1; v < n; v++) res = std::max(res, g[u][v]);

	if (res == maxN) std::cout << "DISCONNECTED\n";
	else std::cout << res << '\n';
}


int main() {
	//freopen("1056.inp", "r", stdin);
	//freopen("1056.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int cntq = 0;
	while (std::cin >> n >> m && n) {
		++cntq, std::cout << "Network " << cntq << ": ";
		Prepare();
		Process();
	}
}