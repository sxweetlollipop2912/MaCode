//AC UVa
#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

#define maxQ 1001
#define maxA 3001
#define maxN 3001
#define maxK 10001
#define qnum first
#define per second
#define id first
#define nper second

typedef int maxn, maxk;
typedef long long maxa;
typedef std::pair <maxn, maxa> info;
typedef std::pair <maxk, maxa> pqueue;
typedef std::string str;

std::vector <info> reg;
maxk K;

class cmp {
public:
	bool operator() (const pqueue &x, const pqueue &y) {
		return x.nper > y.nper || (x.nper == y.nper && reg[x.id].qnum > reg[y.id].qnum);
	}
};
std::priority_queue < pqueue, std::vector <pqueue>, cmp > pq;


void Prepare() {
	str s;
	maxk cnt = 0;

	while (std::cin >> s && s != "#") {
		maxa a;
		maxn n;
		std::cin >> n >> a;

		reg.push_back(info(n, a));
		pq.push(pqueue(cnt++, a));
	}
	std::cin >> K;
}


void Process() {
	while (K--) {
		std::cout << reg[pq.top().id].qnum << '\n';
		pq.push(pqueue(pq.top().id, pq.top().nper + reg[pq.top().id].per));
		pq.pop();
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}