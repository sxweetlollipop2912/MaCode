// AC Kattis
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

#define maxN 502

typedef int maxn;
typedef std::string str;

maxn n, par[maxN], d[maxN][maxN];
std::unordered_map <str, maxn> map;
str name[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n;
	str s;
	for (maxn i = 0, cnt = 0; i < n; i++) std::cin >> s, map[s] = ++cnt, name[cnt] = s;

	for (maxn i = 1; i <= n; i++) std::fill(d[i], d[i] + n + 1, maxN);

	for (maxn ii = 0, j; ii < n; ii++) {
		std::cin >> s >> j; maxn u = map[s];

		for (maxn jj = 0; jj < j; jj++) {
			std::cin.ignore(); getline(std::cin, s);
			std::stringstream ss(s);
			ss >> s;
			while (ss >> s) {
				if (s.back() == ',') s.erase(s.size() - 1);
				maxn v = map[s];
				ad[u].push_back(v); d[u][v] = 1;
			}
		}
	}
}


void Floyd() {
	for (maxn k = 1; k <= n; k++) for (maxn i = 1; i <= n; i++) for (maxn j = 1; j <= n; j++)
		d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
}


bool Process() {
	Floyd();

	maxn mn = 1;
	for (maxn i = 2; i <= n; i++) if (d[i][i] < d[mn][mn]) mn = i;
	if (d[mn][mn] == maxN) return 0;

	par[mn] = mn;
	for (maxn i = d[mn][mn] - 1, u = mn; i >= 0; i--){
		std::cout << name[u] << ' ';
		for (maxn j = 0; j < ad[u].size(); j++) {
			maxn v = ad[u][j];
			if (par[v] || d[v][mn] != i) continue;
			u = v, par[v] = u; break;
		}
	}
	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "SHIP IT";
}