#include "pch.h"
#include <iostream>
#include <string>

#define maxN 301

typedef int maxn, maxq;
typedef std::string str;

maxn n; 
str s;


bool cmp(str s1, str s2) {
	if (s1.size() != s2.size()) return s1.size() > s2.size();
	return s1 > s2;
}


void Process() {
	str sub = s.substr(1, s.size() - 1), s1 = s.substr(0, 1);

	if (!cmp(sub, s1)) std::cout << "NO\n";
	else std::cout << "YES\n2\n" << s1 << ' ' << sub << '\n';
}


int main() {
	maxq q;
	std::cin >> q;
	
	while (q--) {
		std::cin >> n >> s;
		Process();
	}
}