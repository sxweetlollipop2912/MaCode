//AC UVa
//AC Kattis
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

#define maxN 1000001
#define maxA 1000000001

typedef long maxn;
typedef long long maxa;

maxn n, res;
maxa a[maxN];
std::queue <maxa> queue;
std::unordered_set <maxa> set;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++)
		std::cin >> a[i];
}


void Init() {
	set.clear();
	queue = std::queue <maxa>();
}


void Check(const maxa &x) {
	if (set.find(x) == set.end()) return;

	maxa tmp;
	do {
		tmp = queue.front();
		queue.pop();
		set.erase(tmp);
	} while (tmp != x);
}


void Add(const maxa &x) {
	set.insert(x);
	queue.push(x);
}


void Process() {
	res = 1;

	for (maxn i = 0; i < n; i++) {
		Check(a[i]);
		Add(a[i]);
		res = std::max(res, (maxn)queue.size());
	}

	std::cout << res << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int K;
	std::cin >> K;

	while (K--) {
		Init();
		Prepare();
		Process();
	}
}