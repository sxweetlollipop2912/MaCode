#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>

#define maxN 202
#define maxB 8
#define maxK 1000000000000000000
#define MAXe (maxk)26

typedef int maxn, maxb;
typedef long long maxk;
typedef std::string str;

maxn n, begin, end;
str s;


void Prepare() {
	n = s.size();
}


maxn oppo(const maxn &n, const maxn &x) {
	return n - x - 1;
}

maxk get(const maxn &x) {
	return s[x] - 'a' + 1;
}


str reverseString(str s) {
	std::reverse(s.begin(), s.end());
	return s;
}

bool ifPalindrome(const str &s) {
	maxn m = (s.size() - 1) / 2;

	if (s.size() % 2 == 0) return s.substr(0, m + 1) == reverseString(s.substr(m + 1, m + 1));
	return s.substr(0, m) == reverseString(s.substr(m + 1, m));
}

maxb GetB(const str &s) {
	if (end == begin || !ifPalindrome(s.substr(begin, end - begin + 1))) return 0;
	end /= 2;
	return 1 + GetB(s);
}


maxk Prev_Palindrome(const str &s) {
	maxk f[2], all = 1;
	maxn n = s.size(), i = (n - 1) / 2;
	bool equal = 1, p = 0;
	f[p] = 0;

	for (i; i >= 0; i--) {
		p = !p;
		f[p] = (get(i) - 1) * all + f[!p] + (get(i) < get(oppo(n, i))) * equal;
		all *= MAXe;
		equal = (get(i) == get(oppo(n, i))) * equal;
	}

	return f[p];
}


maxk GetK(const str &s) {
	maxn n = s.size();
	maxk re = -Prev_Palindrome(s), rest = 1;
	
	for (maxn i = n - 1; i >= 0; i--) {
		re = re + (get(i) - 1) * rest;
		rest *= MAXe;
	}

	return re + 1;
}


int main() {
	while (getline(std::cin, s)) {
		Prepare();
		std::cout << n << ' ';

		begin = 0;
		end = n - 1;
		std::cout << GetB(s) << ' ';

		std::cout << GetK(s.substr(begin, end - begin + 1)) << '\n';
	}
}