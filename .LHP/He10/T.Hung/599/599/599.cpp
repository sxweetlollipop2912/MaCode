// AC UVa
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>

#define maxN 27
#define maxM 263
#define root first
#define rank second
#define id(x) ((x) - 'A')

typedef int maxn;
typedef long maxm;
typedef std::pair <maxn, maxn> info_t;
typedef std::string str;

maxn n, trees, cnt;
bool ex[maxN];
info_t info[maxN];
str s;


void Init() {
	trees = cnt = 0;
	for (maxn i = 0; i < maxN; i++) {
		ex[i] = 0;
		info[i].root = i;
		info[i].rank = 0;
	}
}


maxn Root(maxn x) {
	while (x != info[x].root) x = info[x].root;
	return x;
}


void Union(maxn x, maxn y) {
	x = Root(x);
	y = Root(y);
	if (x == y) return;

	if (info[x].rank < info[y].rank) {
		info[x].root = y;
	}
	else {
		info[y].root = x;
		if (info[y].rank == info[x].rank) ++info[x].rank;
	}
}


void Connect(const maxn x, const maxn y) {
	if (!(ex[x] | ex[y])) {
		++trees;
		++++cnt;
	}
	else if (ex[x] & ex[y]) 
		--trees;
	else cnt++;

	ex[x] = ex[y] = 1;
	Union(x, y);
}


void Process() {
	while (getline(std::cin, s) && s[0] != '*') {
		Connect(id(s[1]), id(s[3]));
	}

	getline(std::cin, s);
	n = s.size() / 2 + 1;

	std::cout << "There are " << trees <<  " tree(s) and " << n - cnt << " acorn(s).\n";
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int test;
	std::cin >> test;
	getline(std::cin, s);

	while (test--) {
		Init();
		Process();
	}
}