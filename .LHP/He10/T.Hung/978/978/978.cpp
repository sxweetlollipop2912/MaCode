//TLE UVa
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 100001
#define maxA 101
#define fi first
#define se second

typedef long maxn;
typedef int maxa;

maxn n1, n2, B;
std::priority_queue <maxa, std::vector <maxa> > p1, p2;


void Prepare() {
	std::cin >> B >> n1 >> n2;

	for (maxn i = 0; i < n1; i++) {
		maxa a;
		std::cin >> a;
		p1.push(a);
	}

	for (maxn i = 0; i < n2; i++) {
		maxa a;
		std::cin >> a;
		p2.push(a);
	}
}


void Fight(const maxn &B) {
	std::vector <std::pair <maxa, maxa> > re;

	for (maxn i = 0; i < B; i++) {
		maxa lose = std::min(p1.top(), p2.top());
		re.push_back(std::make_pair(p1.top() - lose, p2.top() - lose));

		p1.pop(); p2.pop();
	}

	for (maxn i = 0; i < re.size(); i++) {
		if (re[i].fi) p1.push(re[i].fi);
		if (re[i].se) p2.push(re[i].se);
	}
}


void OutResult() {
	if (p1.empty() && p2.empty()) std::cout << "green and blue died\n";
	else if (p1.empty()) std::cout << "blue wins\n";
	else std::cout << "green wins\n";
}


void Init() {
	p1 = p2 = std::priority_queue <maxa, std::vector <maxa> >();
}


void Process() {
	while (!p1.empty() && !p2.empty()) {
		Fight(std::min(B, (maxn)std::min(p1.size(), p2.size())));
	}

	OutResult();
	while (!p1.empty())
		std::cout << p1.top() << '\n', p1.pop();
	while (!p2.empty())
		std::cout << p2.top() << '\n', p2.pop();
}


int main() {
	std::ios_base::sync_with_stdio(0);

	int K;
	std::cin >> K;

	do {
		Prepare();
		Process();
	} while (--K, std::cout << '\n');
}