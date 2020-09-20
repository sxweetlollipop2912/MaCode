#include <iostream>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <string>

#define maxN 100001

typedef int maxn, maxa;
typedef std::string str;

maxn n, id[2][maxN], root[maxN], size[maxN], CNT;
maxa rep[maxN];
std::unordered_map <str, maxn> map;


maxa Num(const str& s) {
	maxa re = 0;
	for (int i = s.size() - 1; i >= 0; i--) re = re * 10 + (s[i] - '0');
	return re;
}


void Prepare() {
	std::cin >> n;

	for(maxn b = 0; b <= 1; b++) for (maxn i = 0; i < n; i++) {
		str s; std::cin >> s;
		if (map.find(s) != map.end()) id[b][i] = map[s];
		else {
			id[b][i] = map[s] = CNT, root[CNT] = CNT, size[CNT] = 1;
			if (s[0] >= '0' && s[0] <= '9') rep[CNT] = Num(s);
			++CNT;
		}
	}
}


bool Union(maxn x, maxn y) {
	while (x != root[x]) x = root[x];
	while (y != root[y]) y = root[y];

	if (x == y) return 1;

	if (size[x] < size[y]) std::swap(x, y);
	root[y] = x, size[x] += size[y], rep[x] = !rep[x] ? rep[y] : rep[x];

	return rep[x] == rep[y] || !rep[y];
}


bool Process() {
	for (maxn i = 0; i < n; i++) {
		if (!Union(id[0][i], id[1][i])) return 0;
	}
	std::cout << "YES";
	return 1;
}


int main() {
	//freopen("replace.inp", "r", stdin);
	//freopen("replace.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "NO";
}