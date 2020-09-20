#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>

#define maxN 1000001

typedef long maxn;
typedef std::string str;

maxn na, nb, da[maxN], res;
str a, b;
bool even;


void Prepare() {
	std::cin >> a >> b;
	na = a.size(); nb = b.size();

	for (maxn i = 1; i < na; i++) {
		da[i] = da[i - 1] + (bool)(a[i] != a[i - 1]);
	}
}


void Process() {
	even = 1;
	for (maxn i = 0; i < nb; i++)
		if (a[i] != b[i]) even = !even;

	res = even;
	for (maxn l = 1; l <= na - nb; l++) {
		maxn r = l + nb - 1;
		if ((da[r] - da[l - 1]) & 1) even = !even;
		res += even;
	}

	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}