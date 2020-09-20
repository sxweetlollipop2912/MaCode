#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define maxN 301

typedef int maxn;
typedef std::string str;

str s;
maxn f[maxN][maxN], n;


void Prepare() {
	getline(std::cin, s);
	n = s.size();
}


bool valid(const char &n1, const char &n2) {
	return (n1 == '(' && n2 == ')') || (n1 == '{' && n2 == '}') || (n1 == '[' && n2 == ']');
}


void Process() {
	for (maxn i = 0; i < n - 1; i++) {
		f[i][i] = 1;
		f[i][i + 1] = valid(s[i], s[i + 1]) ? 0 : 2;
	}
	f[n - 1][n - 1] = 1;

	for (maxn len = 3; len <= n; len++) 
		for (maxn i = 0; i < n - len + 1; i++) {

			maxn j = i + len - 1;
			f[i][j] = valid(s[i], s[j]) ? f[i + 1][j - 1] : maxN;

			for (maxn k = i; k < j; k++) 
				f[i][j] = std::min(f[i][k] + f[k + 1][j], f[i][j]);
		}

	std::cout << f[0][n - 1];
}


int main() {
	//freopen("dayngoac.inp", "r", stdin);
	//freopen("dayngoac.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}