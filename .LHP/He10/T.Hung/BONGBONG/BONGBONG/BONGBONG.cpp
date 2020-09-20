#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

#define maxN 200001
#define maxA (maxa)1000000000
#define minA (maxa)(-maxA)

typedef long maxn;
typedef long double maxa;

maxn n;
maxa x[maxN], y[maxN];
std::vector <maxn> stack;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> x[i] >> y[i];
}


maxa cal(const maxn &tryR, const maxn &target) {
	return pow(x[tryR] - x[target], 2) / ((maxa)4 * y[tryR]);
}


maxa Add(const maxn &target) {
	while (!stack.empty()) {
		maxn tryR = stack.back();
		y[target] = std::min(y[target], cal(tryR, target));
		if (y[target] >= y[tryR]) stack.pop_back();
		else break;
	}
	stack.push_back(target);
	return y[target];
}


void Process() {
	std::cout << std::fixed << std::setprecision(3);
	for (maxn i = 0; i < n; i++)
		std::cout << Add(i) << '\n';
}


int main() {
	//freopen("bongbong.inp", "r", stdin);
	//freopen("bongbong.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}