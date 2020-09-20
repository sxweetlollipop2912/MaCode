#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>

#define maxN 101
#define maxL 11
#define maxC 27
#define loop -1
#define vary -2
#define num(c) ((c) - 'a')

typedef int maxn, maxl;
typedef char maxa;
typedef std::string str;

maxn ns, n, id[maxC], cnt[maxC];
bool done[maxC];
std::vector <maxa> list, res;
std::vector <maxn> ad[maxC];


void Set_order(const str& s1, const str& s2) { // s1 <= s2
	for (maxl i = 0; i < std::min(s1.size(), s2.size()); i++) {
		if (s1[i] == s2[i]) continue;
		ad[id[num(s1[i])]].push_back(id[num(s2[i])]);
		++cnt[id[num(s2[i])]];
		return;
	}
}

void Set_index(const str& s) {
	for (maxl i = 0; i < s.size(); i++) {
		if (id[num(s[i])]) continue;
		id[num(s[i])] = ++n;
		list.push_back(s[i]);
	}
}


void Prepare() {
	str s[2]; bool p = 0;
	std::cin >> ns;

	for (maxn i = 0; i < ns; i++) {
		p = !p; std::cin >> s[p];
		Set_index(s[p]);
		Set_order(s[!p], s[p]);
	}
}


maxn Find() {
	maxn re = 0;
	for (maxn i = 1; i <= n; i++) {
		if (done[i] || cnt[i]) continue;
		if (re) return vary;
		re = i;
	}
	return !re ? loop : re;
}


str Process() {
	for (maxn i = 1; i <= n; i++) {
		maxn cur = Find();
		if (cur == vary) return "?";
		if (cur == loop) return "!";
		for (maxn j = 0; j < ad[cur].size(); j++) --cnt[ad[cur][j]];
		res.push_back(list[cur - 1]); done[cur] = 1;
	}
	for (maxn i = 0; i < res.size(); i++) std::cout << res[i];
	return "";
}


int main() {
	//freopen("bcc.inp", "r", stdin);
	//freopen("bcc.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	std::cout << Process();
}