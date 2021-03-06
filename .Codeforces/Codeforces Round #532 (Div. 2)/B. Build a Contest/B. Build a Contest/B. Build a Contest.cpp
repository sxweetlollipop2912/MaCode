#include "pch.h"
#include <iostream>

#define maxN 100001 //prob
#define maxK 100001 //dif

typedef long maxn, maxk;

maxn n, r[maxN], cur[maxK];
maxk k;


int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> k >> n;

	for (maxn i = 0; i < n; i++) {
		maxk a;
		std::cin >> a;

		r[cur[a]]++;
		if (r[cur[a]] == k) std::cout << 1;
		else std::cout << 0;

		cur[a]++;
	}
}