#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define maxN 251
#define maxA 10000001

typedef int maxn;
typedef long maxa;

std::string s;
maxa N, E;


void Prepare() {
	std::cin >> s;
}


void Process() {
	maxa x = 0;
	for (maxn i = 0; i < s.size(); i++) {
		if (s[i] == 'N')
			N += x, x = 0;
		else if (s[i] == 'S')
			N -= x, x = 0;
		else if (s[i] == 'E')
			E += x, x = 0;
		else if (s[i] == 'W')
			E -= x, x = 0;
		else x = x * 10 + (s[i] - '0');
	}
	if (E > 0) std::cout << E << "E";
	else if (E < 0) std::cout << (-E) << "W";

	if (N > 0) std::cout << N << "N";
	else if (N < 0) std::cout << (-N) << "S";
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}