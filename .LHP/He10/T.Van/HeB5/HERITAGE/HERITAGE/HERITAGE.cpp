#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define maxN 27
#define left first
#define right second
#define id(x) ((x) - 'A')
#define ch(x) ((char)((x) + 'A'))
#define none -1

typedef int maxn;
typedef std::pair <maxn, maxn> child_t;
typedef std::string str;

maxn n, pospr[maxN], posin[maxN];
child_t child[maxN];
str in, pre;


void Prepare() {
	std::cin >> in >> pre;
	n = in.size();

	for (maxn i = 0; i < n; i++) 
		pospr[id(pre[i])] = posin[id(in[i])] = i;
}


maxn min_pospr(maxn l, const maxn r) {
	maxn re = id(in[l]);
	while (++l <= r) 
		if (pospr[re] > pospr[id(in[l])]) re = id(in[l]);
	return re;
}


maxn Try(const maxn l, const maxn r) {
	if (l > r) return none;

	maxn node = min_pospr(l, r);
	child[node].left = Try(l, posin[node] - 1);
	child[node].right = Try(posin[node] + 1, r);
	return node;
}


void DFS(const maxn x) {
	if (x == none) return;
	DFS(child[x].left);
	DFS(child[x].right);
	std::cout << ch(x);
}


void Process() {
	DFS(Try(0, n - 1));
}


int main() {
	//freopen("heritage.inp", "r", stdin);
	//freopen("heritage.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}