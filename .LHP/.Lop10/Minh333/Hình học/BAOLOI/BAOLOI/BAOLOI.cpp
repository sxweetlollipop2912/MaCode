// Monotone Chain
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 1002
//#define maxA 1e3
//#define minA -1e3
//#define maxC 1e6
//#define epsilon 0.000000001
#define x first
#define y second

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> co;

maxn n, id[maxN];
co a[maxN];
std::vector <maxn> res;


bool cmp(const maxn &id1, const maxn &id2) {
	return (a[id1].x < a[id2].x) || (a[id1].x == a[id2].x && a[id1].y < a[id2].y);
}


void Prepare() {
	std::cin >> n;

	for (maxn i = 1; i <= n; i++) {
		std::cin >> a[i].x >> a[i].y;
		id[i] = i;
	}

	res.resize(2 * n);
	std::sort(id + 1, id + n + 1, cmp);
}


bool isValid(const co &O, const co &A, const co &B) { // OA & OB
	return (A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x) < 0;
}


void Process() {
	maxn len = 0, least = 2;

	for (maxn i = 1; i <= n; i++) {
		if (a[id[i]] == a[id[i - 1]]) continue;
		while (len >= least && !isValid(a[res[len - 2]], a[res[len - 1]], a[id[i]])) len--;
		res[len++] = id[i];
	}

	least = len + 1;
	for (maxn i = n - 1; i >= 1; i--) {
		if (a[id[i]] == a[id[i + 1]]) continue;
		while (len >= least && !isValid(a[res[len - 2]], a[res[len - 1]], a[id[i]])) len--;
		res[len++] = id[i];
	}

	res.resize(std::max(1, len - 1));
}


void Output() {
	std::cout << res.size() << '\n';
	for (maxn i = 0; i < res.size(); i++) std::cout << res[i] << ' ';
}


int main() {
	//freopen("baoloi.inp", "r", stdin);
	//freopen("baoloi.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
	Output();
}