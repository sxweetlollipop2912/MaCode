// Monotone Chain
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 1002
#define x first
#define y second
#define M 0
#define R 1

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> co;

maxn n, id[maxN], check = 0;
co a[maxN];
std::vector <maxn> res, mark;
bool done[maxN];


bool cmp(const maxn &id1, const maxn &id2) {
	return (a[id1].x < a[id2].x) || (a[id1].x == a[id2].x && a[id1].y < a[id2].y);
}


void Prepare() {
	std::cin >> n;

	for (maxn i = 1; i <= n; i++) {
		std::cin >> a[i].x >> a[i].y;
		id[i] = i;
	}

	std::sort(id + 1, id + n + 1, cmp);

	for (maxn i = 2; i <= n; i++) {
		if (a[id[i]] != a[id[i - 1]]) continue;
		done[id[i]] = 1;
		check++;
	}
}


bool cross(const co &O, const co &A, const co &B, const bool &opt) { // OA & OB
	maxa cross = (A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x);
	return (opt == M && cross <= 0) || (opt == R && cross < 0);
}


void Process(std::vector <maxn> &vec, const bool &opt) {
	vec.resize(2 * n);
	maxn len = 0, least = 2;

	for (maxn i = 1; i <= n; i++) {
		if (done[id[i]]) continue;
		while (len >= least && !cross(a[vec[len - 2]], a[vec[len - 1]], a[id[i]], opt)) len--;
		vec[len++] = id[i];
	}

	least = len + 1;
	for (maxn i = n - 1; i >= 1; i--) {
		if (done[id[i]]) continue;
		while (len >= least && !cross(a[vec[len - 2]], a[vec[len - 1]], a[id[i]], opt)) len--;
		vec[len++] = id[i];
	}

	vec.resize(std::max(1, len - 1));
}


void Output() {
	std::cout << res.size() << '\n';
	for (maxn i = 0; i < res.size(); i++) std::cout << res[i] << ' ';
	std::cout << '\n';

	for (maxn i = 0; i < mark.size(); i++) {
		check += done[mark[i]] == 0;
		done[mark[i]] = 1;
	}
}


int main() {
	//freopen("baoloi-n.inp", "r", stdin);
	//freopen("baoloi-n.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();

	while (check != n) {
		Process(mark, M);
		Process(res, R);
		Output();
	}
}