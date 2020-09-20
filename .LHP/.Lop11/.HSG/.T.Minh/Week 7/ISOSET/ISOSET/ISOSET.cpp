#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxQ 1001
#define maxN 51
#define maxD 11
#define DIGIT 9
#define num(c) ((c) - '0')

typedef int maxa, maxn;
typedef long maxr;
typedef std::string str;


bool Check(const str& s1, const str& s2) {
	maxn pos1[maxD] = {}, pos2[maxD] = {};

	if (s1.size() != s2.size()) return 0;

	for (maxn i = 0; i < s1.size(); i++) {
		if (pos1[num(s1[i])] != pos2[num(s2[i])]) return 0;
		pos1[num(s1[i])] = pos2[num(s2[i])] = i + 1;
	}
	return 1;
}


maxr Count(const str& s) {
	bool exist[maxD] = {}; maxn cnt = 0;
	for (maxn i = 0; i < s.size(); i++) cnt += !exist[num(s[i])], exist[num(s[i])] = 1;
	maxr re = 1;
	for (maxn i = 1; i < cnt; i++) re *= (DIGIT - i + 1);
	return re * DIGIT;
}


void Process() {
	char opt; str s1, s2;

	while (std::cin >> opt) {
		if (opt == 'V') {
			std::cin >> s1 >> s2;
			if (Check(s1, s2)) std::cout << "YES\n";
			else std::cout << "NO\n";
		}
		else {
			std::cin >> s1;
			std::cout << Count(s1) << '\n';
		}
	}
}


int main() {
	//freopen("isoset.inp", "r", stdin);
	//freopen("isoset.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Process();
}