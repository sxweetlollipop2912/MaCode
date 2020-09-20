#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>

#define maxN 600001
#define maxA 300000000
#define request "#"

typedef long maxn, maxa;
typedef std::string str;

std::priority_queue < maxa, std::vector <maxa> > pqmax;
std::priority_queue < maxa, std::vector <maxa>, std::greater<maxa> > pqmin;
maxn cookie;


void Add(const maxa &a) {
	cookie++;
	if (pqmax.empty() || a <= pqmax.top()) pqmax.push(a);
	else pqmin.push(a);

	if (cookie % 2 == 0 && pqmin.size() == pqmax.size()) {
		pqmax.push(pqmin.top());
		pqmin.pop();
	}

	if (cookie % 2 == 1 && pqmax.size() - pqmin.size() > 2) {
		pqmin.push(pqmax.top());
		pqmax.pop();
	}
}


maxa SendCookie() {
	maxa re = pqmax.top();
	pqmax.pop();
	
	cookie--;
	if (cookie && cookie % 2 == 0) {
		pqmax.push(pqmin.top());
		pqmin.pop();
	}

	return re;
}


maxa Str2Num(const str &s) {
	maxa re = 0;
	for (int i = 0; i < s.size(); i++) re = re * 10 + (s[i] - '0');
	return re;
}


int main() {
	freopen("cookie.inp", "r", stdin);
	freopen("cookie.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	str s;
	while (getline(std::cin, s)) {
		if (s == request) std::cout << SendCookie() << '\n';
		else Add(Str2Num(s));
	}
}