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


void cal(std::string s) {
	maxn op = 0, cl = 0;

	for (maxn i = 0; i < s.size(); i++) {
		if (s[i] == '(') cl++;

		else {
			if (cl) cl--;
			else op++;
		}
	}
	
	if (op && cl) return;

	if (op) open[op]++;
	else if (cl) close.push_back(cl);
	else open[0]++;
}

void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		cal(s);
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
