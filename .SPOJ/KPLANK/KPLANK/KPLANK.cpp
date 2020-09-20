#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define maxN 1000002
#define maxA 1000000001
#define hi first
#define qu second

typedef long maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], res;
std::vector <std::pair <maxa, maxn> > stack;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++)
		std::cin >> a[i];
}


void Check(const maxa &a, const maxn &n) {
	if ((maxa)n >= a) res = std::max(res, a);
}


void Push(const maxa &a) {
	maxn n = 1;
	while (!stack.empty() && stack.back().hi >= a) {
		Check(stack.back().hi, stack.back().qu + n - 1);
		n += stack.back().qu;
		stack.pop_back();
	}
	stack.push_back(std::make_pair(a, n));
}


void Process() {
	res = 0;
	for (maxn i = 0; i < n; i++)
		Push(a[i]);
	Push(0);

	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}