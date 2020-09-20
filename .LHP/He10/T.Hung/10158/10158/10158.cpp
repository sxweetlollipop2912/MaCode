// AC UVa
#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 10001
#define root first
#define rank second
#define setf 1
#define sete 2
#define aref 3
#define aree 4
#define none -1

typedef int maxn;
typedef std::pair <maxn, maxn> info_t;

maxn n, hate[maxN];
info_t info[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) {
		info[i].rank = 0;
		info[i].root = i;
		hate[i] = -1;
	}
}


maxn Root(maxn x) {
	while (info[x].root != x) x = info[x].root;
	return x;
}


void Union(maxn x, maxn y) {
	if (x == none || y == none) return;
	x = Root(x);
	y = Root(y);

	if (info[x].rank < info[y].rank) info[x].root = y;
	else {
		info[y].root = x;
		if (info[x].rank == info[y].rank) ++info[x].rank;
	}
}


bool AreFriends(const maxn &x, const maxn &y) {
	return Root(x) == Root(y);
}


bool AreEnemies(const maxn &x, const maxn &y) {
	return hate[Root(x)] == Root(y);
}


bool SetFriend(maxn x, maxn y) {
	x = Root(x);
	y = Root(y);
	if (AreEnemies(x, y)) return 0;

	Union(hate[x], hate[y]);
	Union(x, y);

	y = hate[x] != none ? Root(hate[x]) : hate[y] != none ? hate[y] : none;
	x = Root(x);

	if (y != none) {
		hate[x] = y;
		hate[y] = x;
	}
	return 1;
}


bool SetEnemy(maxn x, maxn y) {
	x = Root(x);
	y = Root(y);
	if (AreFriends(x, y)) return 0;

	Union(x, hate[y]);
	Union(y, hate[x]);

	x = Root(x);
	y = Root(y);
	hate[x] = y;
	hate[y] = x;
	return 1;
}


void Process() {
	int opt;
	maxn x, y;
	while (std::cin >> opt >> x >> y) {
		if (!opt) break;
		if (opt == setf) {
			if (!SetFriend(x, y)) std::cout << "-1\n";
		}
		else if (opt == sete) {
			if (!SetEnemy(x, y)) std::cout << "-1\n";
		}
		else if (opt == aref)
			std::cout << AreFriends(x, y) << '\n';
		else
			std::cout << AreEnemies(x, y) << '\n';
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}