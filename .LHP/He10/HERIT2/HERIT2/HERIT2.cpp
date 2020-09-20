#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define maxN 29
#define id(x) ((x) - 'A')
#define ch(x) ((char)((x) + 'A'))
#define dummy 27

typedef int maxn;
typedef std::string str;

maxn n, pre[maxN], pos[maxN], par[maxN];
str Pre, Pos;
bool written[maxN];


void Prepare() {
	std::cin >> Pre >> Pos;
	n = Pre.size();

	for (maxn i = 0; i < n; i++)
		pre[id(Pre[i])] = pos[id(Pos[i])] = i;

	pos[dummy] = -2;
}


maxn min_pre(maxn l, const maxn r) {
	if (l > r) return dummy;
	maxn re = id(Pos[l]);
	while (++l <= r)
		if (pre[re] > pre[id(Pos[l])]) re = id(Pos[l]);
	return re;
}


maxn Try(const maxn l, const maxn r) {
	if (l < 0 || r < 0 || l > r) return dummy;

	maxn node = id(Pos[r]), nleft = min_pre(l, r - 1);
	par[Try(pos[nleft] + 1, r - 1)] = par[Try(l, pos[nleft])] = node;
	return node;
}


void write(const maxn ID) {
	if (written[ID]) return;
	std::cout << ch(ID);
	written[ID] = 1;
}

void Process() {
	Try(0, n - 1);

	std::fill(written, written + maxN, 0);
	for (maxn i = 0; i < n; i++) {
		write(id(Pos[i]));
		write(par[id(Pos[i])]);
	}
	//std::cout << '\n' << pos[dummy] << ' ' << par[dummy];
}


int main() {
	//freopen("herit2.inp", "r", stdin);
	//freopen("herit2.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}