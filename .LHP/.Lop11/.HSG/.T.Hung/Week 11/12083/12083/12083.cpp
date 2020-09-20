#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_map>

#define maxN 501
#define M 0
#define F 1

typedef int maxn, maxa;
typedef std::string str;

maxn n, mus[maxN], spo[maxN];
maxa h[maxN];
bool gen[maxN], g[maxN][maxN], seen[maxN], mch[maxN];
std::unordered_map <str, maxn> music, sport;
std::vector <maxn> f, m;


maxn idx(const str& s, std::unordered_map <str, maxn>& map, maxn cnt) {
	if (map.find(s) == map.end()) map[s] = cnt, ++cnt;
	return map[s];
}

void Prepare() {
	std::cin >> n;

	for (maxn i = 0, cntm = 0, cnts = 0; i < n; i++) {
		str s;
		std::cin >> h[i] >> s;
		gen[i] = s == "F";
		//if (s == "F") f.push_back(i);
		//else m.push_back(i);
		std::cin >> s; mus[i] = idx(s, music, cntm);
		std::cin >> s; spo[i] = idx(s, sport, cnts);
	}

	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) {
		g[i][j] = g[j][i] = gen[i] != gen[j] && abs(h[i] - h[j]) <= 40 && mus[i] == mus[j] && spo[i] != spo[j];
	}
	std::cout << g[2][3] << '\n';
}


bool DFS(maxn u) {
	for (maxn v = 0; v < n; v++)
		if (gen[v] == F && g[u][v] && !seen[v]) {
			seen[v] = 1;
			if (mch[v] < 0 || DFS(mch[v]))
				return mch[v] = u, 1;
		}
	return 0;
}


maxn maxBPM() {
	std::fill(mch, mch + n, -1);
	maxn res = 0;
	for (maxn u = 0; u < n; u++) {
		if (gen[u] != M) continue;
		std::fill(seen, seen + n, 0);
		if (DFS(u)) ++res;
	}
	return res;
}


void Process() {
	std::cout << n - maxBPM();
}


int main() {
	Prepare();
	Process();
}