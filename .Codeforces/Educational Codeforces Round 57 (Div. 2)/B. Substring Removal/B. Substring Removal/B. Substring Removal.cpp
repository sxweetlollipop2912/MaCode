#include "pch.h"
#include <iostream>
#include <string>

#define MOD 998244353
#define maxN 200001

typedef long long maxn;
typedef std::string str;

str s;
maxn n;

int main() {
	std::cin >> n;
	std::cin >> s;
	s += '0';

	maxn l = 0;
	while (l < n - 1 && s[l + 1] == s[l]) l++;
	l += 1;

	maxn r = n - 1;
	while (r > 1 && s[r - 1] == s[r]) r--;
	r = n - r;
	
	maxn re;
	if (s[0] != s[n - 1]) re = (l + r + 1) % MOD;
	else re = (l + 1 + ((l + 1)*r) % MOD) % MOD;

	std::cout << re;
}