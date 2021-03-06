#include "pch.h"
#include <iostream>
#include <string>

#define maxN 500001

typedef size_t maxn;
typedef char maxa;

maxn start, fin;
std::string s;


maxn Count() {
	maxn re = 0;

	for (start; start <= fin; start++)
		if (s[start] == '|') re++;

	return re;
}


int main() {
	std::cin >> s;

	start = s.find("[");
	if (start != std::string::npos) start = s.find(":", start);
	
	fin = s.rfind("]");
	if (fin != std::string::npos) fin = s.rfind(":", fin);

	if (start == std::string::npos || fin == std::string::npos || start >= fin) {
		std::cout << -1;
		return 0;
	}

	//std::cout << start << ' ' << fin << ' ';
	std::cout << Count() + 4;
}