#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <math.h>

#pragma warning (disable:4996)

#define maxN 12000
#define epsilon 0.0000000000001
#define log2 1
#define log3 1.584962500721156
#define log5 2.321928094887362
#define MOD 3

typedef int maxn;
typedef double maxa;

maxn n, res;
maxa a, b, c, re[MOD];
std::priority_queue < maxa, std::vector <maxa> > pqueue;
int prev[MOD] = { 2, 0, 1 };


void Prepare() {
	std::cin >> n;
}


maxa cal(maxa a, maxa b, maxa c) {
	return log2 * a + log3 * b + log5 * c;
}


bool isValid(maxa x) {
	return pqueue.empty() || pqueue.top() - x > epsilon;
}


bool Check(maxa x) {

	if (pqueue.size() == n) {
		if (!isValid(x)) return 0;
		pqueue.pop();
	}

	if (x) pqueue.push(x);
	return 1;
}


void PQueue() {
	for (a = 0; isValid(cal(a, 0, 0)); a++)
	for (b = 0; isValid(cal(a, b, 0)); b++)
	for (c = 0; Check(cal(a, b, c)); c++) {}
}


void Process() {
	for (int i = 0; i < MOD; i++) {
		re[i] = pqueue.top();
		pqueue.pop();
	}

	int p = 1;

	while (!pqueue.empty()) {
		res += (abs(re[(p + 1) % MOD] + re[(p + 2) % MOD] - (2 * re[p])) <= epsilon);
		
		re[prev[p]] = pqueue.top();
		pqueue.pop();

		p = (p + 1) % MOD;
	}
}


int main() {
	//freopen("bts.out", "w", stdout);

	Prepare();
	PQueue();
	Process();

	std::cout << res;
}