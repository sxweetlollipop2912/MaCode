#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

#define maxN 30001
#define pos first
#define U second.first
#define V second.second
#define num(c) ((c) - 'a')

typedef int maxn;
typedef std::pair <char, char> e_t;
typedef std::pair <maxn, e_t> inf_t;
typedef std::string str;

maxn n, prev[maxN];
str s[maxN];
bool done[27], inS[27], ad[27][27];
std::vector <inf_t> u[maxN], d[maxN];
std::vector <maxn> res;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> s[i];
	std::sort(s, s + n);
}


bool DFS(const int u) {
	if (done[u]) return 1;
	done[u] = inS[u] = 1;
	for (int v = 0; v < 26; v++) {
		if (u != v && ad[u][v] && (inS[v] || !DFS(v))) return 0;
	}
	inS[u] = 0;
	return 1;
}


bool Check(const maxn idx) {
	if (idx && u[idx].empty()) return 0;

	for (int i = 0; i < 26; i++) std::fill(ad[i], ad[i] + 26, 0);
	for (int i = 0; i < u[idx].size(); i++) ad[num(u[idx][i].U)][num(u[idx][i].V)] = 1;
	for (int i = 0; i < d[idx].size(); i++) ad[num(d[idx][i].U)][num(d[idx][i].V)] = 1;

	std::fill(done, done + 26, 0);
	for (int i = 0; i < 26; i++) 
		if (!done[i] && !DFS(i)) return 0;
	return 1;
}


void Process() {
	for (maxn i = n - 2, is, back; i >= 0; i--) {
		for (is = 0, back = 0; is < s[i].size() && is < s[i + 1].size(); is++) {
			if (s[i][is] != s[i + 1][is]) break;
			while (back != d[i + 1].size() && d[i + 1][back].pos <= is) d[i].push_back(d[i + 1][back++]);
		}
		if (is == s[i].size()) continue;
		d[i].push_back(inf_t(is, e_t(s[i][is], s[i + 1][is])));
		while (back != d[i + 1].size() && d[i + 1][back].pos == is) d[i].push_back(inf_t(is, e_t(s[i][is], d[i + 1][back++].V)));
	}

	for (maxn i = 1, is, back; i < n; i++) {
		for (is = 0, back = 0; is < s[i].size() && is < s[prev[i - 1]].size(); is++) {
			if (s[i][is] != s[prev[i - 1]][is]) break;
			while (back != u[prev[i - 1]].size() && u[prev[i - 1]][back].pos <= is) u[i].push_back(u[prev[i - 1]][back++]);
		}
		if (is == s[prev[i - 1]].size()) {
			u[i].clear(); prev[i] = prev[i - 1]; continue;
		}
		prev[i] = i, u[i].push_back(inf_t(is, e_t(s[i][is], s[prev[i - 1]][is])));
		while (back != u[prev[i - 1]].size() && u[prev[i - 1]][back].pos == is) u[i].push_back(inf_t(is, e_t(s[i][is], u[prev[i - 1]][back++].V)));
	}

	for (maxn i = 0; i < n; i++)
		if (Check(i)) res.push_back(i);

	std::cout << res.size() << '\n';
	for (maxn i = 0; i < res.size(); i++) std::cout << s[res[i]] << '\n';
}


int main() {
	//freopen("alphabet.inp", "r", stdin);
	//freopen("alphabet.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}