#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 400002
#define maxNA 200002
#define maxA 200001
#define maxB 2750132
#define num first
#define edge second

typedef long maxn, maxa;
typedef std::pair <maxa, maxn> pqueue;

//*************************************************************
bool snt[maxB];
std::vector <maxa> prime;


void Era() {
	prime.reserve(maxA);

	snt[0] = snt[1] = 1;
	for (long long i = 2; i < maxB; i++) {
		if (snt[i]) continue;

		prime.push_back(i);
		long long x = i * i;
		while (x < maxB) {
			snt[x] = 1;
			x += i;
		}
	}
}

maxa Div(const maxa &x) {
	for (maxa i = 2; i <= x; i++)
		if (x % i == 0) return x / i;
	return 1;
}

maxa ToB(const maxa &x) {
	if (x >= maxA) return 0;
	if (!snt[x]) return prime[x - 1];
	return Div(x);
}
//*************************************************************


maxn na, nb, cnt[maxB], adj[maxB];
maxa b[maxN], toB[maxN];
std::vector <maxa> ad[maxB];

class cmp {
public:
	bool operator() (const pqueue &x, const pqueue &y) {
		return x.edge > y.edge;
	}
};
std::priority_queue <pqueue, std::vector <pqueue>, cmp > pq;


void Prepare() {
	std::cin >> na;
	nb = 2 * na;

	for (maxn i = 1; i <= nb; i++) {
		std::cin >> b[i];
		++cnt[b[i]];
	}

	std::sort(b + 1, b + nb + 1);

	for (maxn i = 1; i <= nb; i++) {
		toB[i] = 0;
		if (b[i] >= maxA) continue;

		if (b[i] != b[i - 1]) {
			toB[i] = ToB(b[i]);
			ad[toB[i]].push_back(b[i]);
			ad[b[i]].push_back(toB[i]);
		}
		else toB[i] = toB[i - 1];

		++adj[toB[i]];
	}

	for (maxn i = 1; i <= nb; i++) {
		if (b[i] == b[i - 1]) continue;
		adj[b[i]] += cnt[toB[i]];
		pq.push(pqueue(b[i], adj[b[i]]));
	}
}


void Clear() {
	while (!cnt[pq.top().num] || pq.top().edge != adj[pq.top().num]) pq.pop();
}


void Delete(const maxa x) {
	maxa y = 0;
	while (!cnt[ad[x][y]]) ++y;
	y = ad[x][y];

	for (maxn i = 0; i < ad[x].size(); i++) {
		--adj[ad[x][i]];
		if (cnt[ad[x][i]]) pq.push(pqueue(ad[x][i], adj[ad[x][i]]));
	}

	for (maxn i = 0; i < ad[y].size(); i++) {
		--adj[ad[y][i]];
		if (cnt[ad[y][i]]) pq.push(pqueue(ad[y][i], adj[ad[y][i]]));
	}

	--cnt[x], --cnt[y];

	//std::cout << x << ' ' << y << '\n';
	if (ToB(x) == y) std::cout << x << ' ';
	else std::cout << y << ' ';

	pq.pop();
}


void Process() {
	for (maxn i = 0; i < na; i++) {
		Clear();
		Delete(pq.top().num);
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Era();
	Prepare();
	Process();
}