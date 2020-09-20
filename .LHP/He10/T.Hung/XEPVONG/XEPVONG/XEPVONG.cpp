#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <vector>

#define maxN 10
#define maxR 1e9
#define epsilon 0.0001

typedef int maxn;
typedef double maxa;

maxn n, id[maxN];
maxa r[maxN], x[maxN], res;
std::vector <maxn> stack;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		std::cin >> r[i];
		id[i] = i;
	}
}

maxa nextX(const maxa x, const maxa R, const maxa Rnext) {
	return x + 2 * pow(R * Rnext, 0.5);
}


maxa Place(const maxn target) {
	x[target] = r[target];

	while (!stack.empty()) {
		maxn tryX = stack.back();
		x[target] = std::max(x[target], nextX(x[tryX], r[tryX], r[target]));
		if (r[target] >= r[tryX]) stack.pop_back();
		else break;
	}

	stack.push_back(target);
	return x[target];
}


maxa Length() {
	stack.clear();
	maxa re = 0;

	for (maxn i = 0; i < n; i++) {
		re = std::max(re, Place(id[i]) + r[id[i]]);
	}

	return re;
}


void Process() {
	res = maxR;

	do {
		res = std::min(res, Length());
	} while (std::next_permutation(id, id + n));

	std::cout << std::fixed << std::setprecision(3) << res;
}


int main() {
	//freopen("xepvong.inp", "r", stdin);
	//freopen("xepvong.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}