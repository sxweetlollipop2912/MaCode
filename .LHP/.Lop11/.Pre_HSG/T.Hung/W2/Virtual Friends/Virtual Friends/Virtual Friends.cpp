// AC Kattis
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

#define maxN 100001
#define root first
#define rank second

typedef long maxn;
typedef std::string str;
typedef std::pair <maxn, maxn> info;

maxn n, size[maxN], CNT;
info set[maxN];
std::unordered_map <str, maxn> map;


void Prepare() {
	std::cin >> n;
	std::fill(size, size + n, 0);
	CNT = -1;
	map.clear();
}


void assign(const str& s, const maxn cnt) {
	map[s] = cnt;
	set[cnt].root = cnt, set[cnt].rank = 0;
	size[cnt] = 1;
}


maxn Union(maxn x, maxn y) {
	while (set[x].root != x) x = set[x].root;
	while (set[y].root != y) y = set[y].root;

	if (x == y) return size[x];

	if (set[x].rank < set[y].rank) 
		set[x].root = y, size[y] += size[x];
	else {
		set[y].root = x, size[x] += size[y];
		if (set[x].rank == set[y].rank) ++set[x].rank;
		return size[x];
	}

	return size[y];
}


void Process() {
	while (n--) {
		str s1, s2;
		std::cin >> s1 >> s2;

		maxn x, y;
		if (map.find(s1) == map.end()) {
			assign(s1, ++CNT);
			x = CNT;
		}
		else x = map[s1];

		if (map.find(s2) == map.end()) {
			assign(s2, ++CNT);
			y = CNT;
		}
		else y = map[s2];

		std::cout << Union(x, y) << '\n';
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	while (q--) {
		Prepare();
		Process();
	}
}