// AC POJ.org
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <iomanip>

#pragma warning(disable:4996)

#define maxN 10001

typedef int maxn;
typedef double maxr;
typedef std::string str;

maxn n;
std::map <str, maxn> map;


void Prepare() {
	n = 0;
	str s;
	while (std::getline(std::cin, s)) {
		++map[s], ++n;
	}
}


void Process() {
	std::cout << std::fixed;
	std::cout << std::setprecision(4);

	for (std::map <str, maxn>::iterator i = map.begin(); i != map.end(); i++) {
		std::cout << (*i).first << ' ' << ((*i).second * 100) / (maxr)n << '\n';
	}
}


int main() {
	//freopen("inp.inp", "r", stdin);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}