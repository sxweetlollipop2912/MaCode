#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

#pragma warning (disable:4996)

#define maxN 101
#define num(c) (int)((c) - '0')
#define add(c1, c2) (char)(num(c1) + num(c2) + '0')
#define sub(c1, c2) (char)(num(c1) - num(c2) + '0')

typedef int maxn;
typedef std::string str;

str s1, s2, s;
maxn n;


void Prepare() {
	s = "";
	while (s1.size() < s2.size()) s1 = "0" + s1;
	while (s2.size() < s1.size()) s2 = "0" + s2;

	for (maxn i = 0; i < s1.size(); i++) {
		maxn i1 = s1.size() - i - 1, i2 = s2.size() - i - 1;
		s += add(s1[i1], s2[i2]);
	}
	//std::cout << s << '\n';
}


bool Check(const str& s) {
	for (maxn i = 1; i < s.size(); i++) 
		if (s[i] > '1' || (s[i - 1] == '1' && s[i] == '1')) return 0;
	return s[0] <= '1';
}


void Consec(str& s) {
	for (maxn i = 2; i < s.size(); i++) {
		char a = (char)std::min(s[i - 1], s[i - 2]);
		s[i] = add(s[i], a);
		s[i - 1] = sub(s[i - 1], a);
		s[i - 2] = sub(s[i - 2], a);
		//std::cout << i << ' ' << s[i - 1] << ' ' << s[i - 2] << ' ' << s[i] << '\n';
	}
}


void Spread(str& s) {
	if (s[s.size() - 1] != '0') s += "0";

	for (maxn i = s.size() - 2; i > 1; i--) {
		if (s[i] <= '1') continue;

		char a = (char)((num(s[i]) / 2) + '0');
		s[i + 1] = add(s[i + 1], a);
		s[i - 2] = add(s[i - 2], a);
		s[i] = (char)((num(s[i]) % 2) + '0');
	}

	if (s[1] > '1') {
		char a = (char)((num(s[1]) / 2) + '0');
		s[0] = add(s[0], a);
		s[2] = add(s[2], a);
		s[1] = (char)((num(s[1]) % 2) + '0');
	}

	if (s[0] > '1') {
		char a = (char)((num(s[0]) / 2) + '0');
		s[1] = add(s[1], a);
		s[0] = (char)((num(s[0]) % 2) + '0');
	}
}


void Output(const str& s) {
	maxn i = s.size() - 1;
	while (i > 0 && s[i] == '0') --i;
	while (i >= 0) std::cout << s[i], --i;
	std::cout << "\n\n";
}


void Process() {
	while (!Check(s)) {
		Consec(s);
		Spread(s);
	}
	Output(s);
}


int main() {
	//freopen("763.inp", "r", stdin);
	//freopen("763.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> s1 >> s2) {
		Prepare();
		Process();
	}
}