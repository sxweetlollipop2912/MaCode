#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 1001
#define maxA 100

typedef int maxn, maxa;

maxn n;
bool st, qu, pr;
int cnt;

std::vector <maxa> stack;
std::queue <maxa> queue;
std::priority_queue < maxa, std::vector <maxa> > pq;


void Init() {
	st = qu = pr = 1;
	cnt = 3;

	stack = std::vector <maxa>();
	queue = std::queue <maxa>();
	pq = std::priority_queue < maxa, std::vector <maxa> >();
}


void Add(const maxa &x) {
	stack.push_back(x);
	queue.push(x);
	pq.push(x);
}


void Pop(const maxa &x) {
	if (stack.empty() || stack.back() != x) cnt -= st, st = 0;
	else stack.pop_back();

	if (queue.empty() || queue.front() != x) cnt -= qu, qu = 0;
	else queue.pop();

	if (pq.empty() || pq.top() != x) cnt -= pr, pr = 0;
	else pq.pop();
}


void Output() {
	if (cnt == 0) std::cout << "impossible\n";
	else if (cnt > 1) std::cout << "not sure\n";
	else if (st) std::cout << "stack\n";
	else if (qu) std::cout << "queue\n";
	else std::cout << "priority queue\n";
}


void Process() {
	Init();

	while (n--) {
		int opt;
		maxa x;
		std::cin >> opt >> x;
		if (opt == 1) Add(x);
		if (opt == 2) Pop(x);
	}

	Output();
}


int main() {
	std::ios_base::sync_with_stdio(0);
	//std::cin.tie(0);

	while (std::cin >> n) Process();
}