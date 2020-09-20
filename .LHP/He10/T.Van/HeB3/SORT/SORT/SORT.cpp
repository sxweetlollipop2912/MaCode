#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

#define maxS 100001
#define maxL 61

typedef long maxn;
typedef std::string str;

str S;
std::vector <str> period;
std::vector <str> alpha;


void Prepare() {
	std::cin >> S;
	S = "." + S;

	maxn i = 1;
	while (S[i] == '.') std::cout << S[i++];

	for (i; i < S.size(); i++) {
		if (S[i] == '.') {
			if (S[i - 1] != '.') period.push_back(".");
			else period.back() += ".";
		}
		else {
			if (S[i - 1] == '.') alpha.push_back(S.substr(i, 1));
			else alpha.back() += S[i];
		}
	}
}


void Process() {
	std::sort(alpha.begin(), alpha.end());

	for (maxn i = 0; i < period.size(); i++) std::cout << alpha[i] << period[i];
	if (period.size() < alpha.size())
		std::cout << alpha[alpha.size() - 1];
}


int main() {
	freopen("sort.inp", "r", stdin);
	freopen("sort.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}