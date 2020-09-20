#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstdio>

#pragma warning (disable:4996)

#define maxN 1001
#define isVar(x) ((x) >= 'a' && (x) <= 'z')

typedef int maxn;
typedef std::string str;

maxn n, cnt[maxN], CNT;
bool assigned[maxN];
std::vector <maxn> ad[maxN];
std::unordered_map <str, maxn> map;


void Init() {
	for (maxn i = 0; i < maxN; i++) {
		assigned[i] = cnt[i] = 0;
		ad[i].clear();
	}
	CNT = 0;
	map.clear();
}


maxn index(const str &s) {
	if (map.find(s) != map.end()) return map[s];
	return (map[s] = CNT++);
}


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		str s, tmp;
		std::cin >> s;

		maxn is = 0;
		while (isVar(s[is])) tmp += s[is], ++is;
		maxn av = index(tmp); assigned[av] = 1;

		is += 3;
		while (is < s.size()) {
			tmp = "";
			while (isVar(s[is])) tmp += s[is], ++is;
			if (tmp != "" && index(tmp) != av) {
				ad[index(tmp)].push_back(av);
				++cnt[av];
			}
			is += 2;
		}
	}
}


bool Process() {
	std::vector <maxn> st;

	for (maxn i = 0; i < CNT; i++) {
		if (!assigned[i]) return 0;
		if (!cnt[i]) st.push_back(i);
	}

	while (!st.empty()) {
		maxn u = st.back(); st.pop_back();
		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i];
			if (!(--cnt[v])) st.push_back(v);
		}
	}

	for (maxn i = 0; i < CNT; i++) if (cnt[i]) return 0;
	return 1;
}


int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q; std::cin >> q;

	for(int cntq = 1; cntq <= q; cntq++) {
		std::cout << "Case #" << cntq << ": ";
		Init();
		Prepare();
		if (Process()) std::cout << "GOOD\n";
		else std::cout << "BAD\n";
	}
}