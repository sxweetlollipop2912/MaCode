#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

#define maxN 100001
#define maxL 500002

typedef long maxn;

maxn open[maxL];
std::vector <maxn> close;
maxn n;


void process(std::string s) {
	maxn op = 0, cl = 0;

	for (maxn i = 0; i < s.size(); i++) {
		cl += s[i] == ')' ? -1 : 1;
		if (cl >= 0) continue;

		op++;
		cl = 0;
	}

	if (op) {
		if (cl) return;
		open[op]++;
	}
	else if (cl) close.push_back(cl);
	else open[0]++;
}

void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		process(s);
	}
}

int main() {
	Prepare();

	maxn re = open[0] / 2;

	while (!close.empty()) {

		maxn tmp = close.back();
		close.pop_back();

		if (!open[tmp]) continue;

		re++;
		open[tmp]--;
	}

	std::cout << re;
}