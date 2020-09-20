// AC UVa
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

#pragma warning(disable:4996)

#define maxN 101

typedef int maxn;
typedef std::string str;

maxn n, cnt[maxN];
std::unordered_map <str, maxn> map;
str word[maxN];
std::vector <maxn> ad[maxN];
std::vector <str> res;


void Init() {
	map.clear();
	for (maxn i = 0; i < n; i++) {
		ad[i].clear(); cnt[i] = 0;
	}
}


void Add(const str& s, maxn& id) {
	if (map.find(s) != map.end()) return;
	word[id] = s, map[s] = id, ++id;
}


void Prepare() {
	for (maxn i = 0, id = 0; i < n; i++) {
		str s; std::cin >> s; Add(s, id); maxn u = map[s];
		getline(std::cin, s);
		std::stringstream ss(s);
		while (ss >> s) {
			Add(s, id); maxn v = map[s];
			ad[u].push_back(v); ++cnt[v];
		}
	}
}


void Process() {
	std::vector <maxn> st;
	for (maxn i = 0; i < n; i++) if (!cnt[i]) st.push_back(i);

	while (!st.empty()) {
		maxn u = st.back(); st.pop_back();
		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i];
			if (!(--cnt[v])) st.push_back(v);
		}
	}

	res.clear();
	for (maxn i = 0; i < n; i++) {
		if (cnt[i]) res.push_back(word[i]);
		//std::cout << i << ' ' << word[i] << ' ' << res_cnt << '\n';
	}
	std::sort(res.begin(), res.end());

	std::cout << res.size() << '\n';
	bool p = 0;
	for (maxn i = 0; i < res.size(); i++) {
		if (p) std::cout << ' '; p = 1;
		std::cout << res[i];
	}
	std::cout << '\n';
}



int main() {
	freopen("1229.inp", "r", stdin);
	freopen("1229.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) {
		Init();
		Prepare();
		Process();
	}
}