#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 200001
#define maxK 200001

typedef long maxn, maxk;
typedef char maxa;

maxn cnt[25], n, time;
maxk k;
char key = 'a' - 1;


void Update() {
	if (time != k) return;
	cnt[key - 'a']++;
	time = 0;
}


int main() {
	std::cin >> n >> k;

	for (maxn i = 0; i < n; i++) {
		char c;
		std::cin >> c;

		if (key == c) {
			time++;
			Update();
		}
		else {
			key = c;
			time = 1;
			Update();
		}
	}

	std::cout << *std::max_element(cnt, cnt + 25);
}