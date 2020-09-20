#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

#define maxN 101

typedef int maxn;
typedef std::string str;

str a[maxN];
maxn n;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


bool cmp(str &s1, str &s2) {
	int len = std::min(s1.size(), s2.size());
	str x1 = s1.substr(0, len), x2 = s2.substr(0, len);
	
	if (x1 == x2) return s1.size() < s2.size();
	return x1 > x2;
}


int main() {
	Prepare();
	std::sort(a, a + n, cmp);
	for (maxn i = 0; i < n; i++) std::cout << a[i];
}