#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 1000001
#define maxA 1002
#define left first
#define right second

typedef long maxn;
typedef int maxa;
typedef std::pair <maxa, maxa> pair;

maxn n, res;
pair a[maxN];
bool done[maxN];
std::vector <maxn> Lid[maxA], Rid[maxA];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i].left >> a[i].right;
		Lid[a[i].left].push_back(i);
		Rid[a[i].right].push_back(i);
	}
}


bool Get(std::vector <maxn> &v) {
	while (!v.empty() && done[v.back()]) v.pop_back();
	return !v.empty();
}


void Fill(const maxn &id) {
	maxa l = a[id].left, r = a[id].right;
	done[id] = 1;

	while (Get(Lid[r])) {
		maxn id_tmp = Lid[r].back();
		done[id_tmp] = 1;
		r = a[id_tmp].right;
	}

	while (Get(Rid[l])) {
		maxn id_tmp = Rid[l].back();
		done[id_tmp] = 1;
		l = a[id_tmp].left;
	}
}


void Process() {
	res = n;
	for (maxn i = 0; i < n; i++) {
		if (done[i]) continue;
		Fill(i);
		++res;
	}
	std::cout << res;
}


int main() {
	//freopen("pie.inp", "r", stdin);
	//freopen("pie.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}