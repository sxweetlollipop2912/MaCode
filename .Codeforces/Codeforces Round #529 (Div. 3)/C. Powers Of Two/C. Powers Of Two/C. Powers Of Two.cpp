// AC
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define maxN 1000000001
#define maxK 200001

typedef long maxn, maxk;

maxn n, len, time;
maxk k;
std::vector <maxn> v;


bool Prepare() {
	std::cin >> n >> k;

	if (k > n) return 0;
	k -= (n % 2);
	
	len = n - (n % 2);
	time = len - k;

	return 1;
}


bool Create() {
	v.push_back(len);

	while (time > 0) {
		len /= 2;
		if (len == 0) return 0;

		v.push_back(std::min(len, time));
		time -= len;
	}

	return 1;
}


int main() {
	if (!Prepare() || !Create()) {
		std::cout << "NO";
		return 0;
	}

	std::cout << "YES\n";
	if (n % 2) std::cout << "1 ";

	maxn pow2 = 1;
	for (maxn i = 0; i < v.size() - 1; i++) {
		for (maxn j = 0; j < v[i] - (2 * v[i + 1]); j++) std::cout << pow2 << ' ';
		pow2 *= 2;
	}

	for (maxn j = 0; j < v[v.size() - 1]; j++) std::cout << pow2 << ' ';
}