// AC
#include "pch.h"
#include <iostream>
#include <string>

#define maxT 101
#define maxL 1001

std::string s;
int t;

void Process() {
	int l = -1, len = s.size();
	bool kt = 1;
	for (int i = 0; i < len / 2 + 1; i++) {
		kt = kt * (s[i] == s[len - i - 1]);
		if (i > 0 && s[i] != s[i - 1]) l = i;
	}
	if (!kt) std::cout << s << '\n';
	else if (l == -1) std::cout << l << '\n';
	else {
		char c = s[l];
		s[l] = s[l - 1];
		s[l - 1] = c;
		std::cout << s << '\n';
	}
}

int main() {
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> s;
		Process();
	}
}