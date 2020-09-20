// AC
#include "pch.h"
#include <iostream>
#include <string>

typedef std::string str;

str s;

void Prepare() {
	std::cin >> s;
}


int main() {
	Prepare();

	str re = s;
	int key = (s.size() - 1) / 2;

	for (int i = key; i >= 0; i--) re[(key - i) * 2] = s[i];
	for (int i = key + 1; i < s.size(); i++) re[(i - key - 1) * 2 + 1] = s[i];
	std::cout << re;
}