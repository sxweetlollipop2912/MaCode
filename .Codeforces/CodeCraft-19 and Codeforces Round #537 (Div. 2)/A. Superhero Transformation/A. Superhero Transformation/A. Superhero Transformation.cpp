#include "pch.h"
#include <iostream>
#include <string>

#define maxA 26
#define maxN 1001

typedef int maxn;

bool a[maxA];
std::string s, s1;


int main() {
	std::cin >> s;
	std::cin >> s1;

	a['a' - 'a'] = 1; a['e' - 'a'] = 1; a['i' - 'a'] = 1; a['o' - 'a'] = 1; a['u' - 'a'] = 1;

	if (s1.size() != s.size()) {
		std::cout << "No";
		return 0;
	}

	for (maxn i = 0; i < s1.size(); i++)
		if (a[s1[i] - 'a'] != a[s[i] - 'a']) {
			std::cout << "No";
			return 0;
		}

	std::cout << "Yes";
}