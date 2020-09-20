// AC UVa
#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 1001
#define maxA 6002
#define maxL 3000
#define weight first
#define load second

typedef int maxn, maxa;
typedef std::pair <maxa, maxa> info;

maxn n, box[maxA];
info a[maxN];


void Prepare() {
	for (maxn i = n - 1; i >= 0; i--) 
		std::cin >> a[i].weight >> a[i].load;
}


void Process() {
	std::fill(box, box + maxA, 0);
	box[a[0].weight] = 1;

	for (maxn i = 1; i < n; i++) {
		maxa w = a[i].weight, l = a[i].load + 1;
		while (--l) {
			if (!box[l]) continue;
			box[l + w] = std::max(box[l + w], box[l] + 1);
		}
		box[w] = std::max(box[w], 1);
	}

	std::cout << *std::max_element(box, box + maxA) << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) {
		Prepare();
		Process();
	}
}