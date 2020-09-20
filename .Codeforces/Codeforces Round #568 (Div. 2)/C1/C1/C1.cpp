#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 200001
//#define maxM 20000001
//#define maxS 20000001

typedef long maxn, maxa;

maxn n;
maxa a[maxN], M, mns;
std::priority_queue <maxa, std::vector <maxa> > mx;
std::priority_queue <maxa, std::vector <maxa>, std::greater<maxa> > mn;


void Prepare() {
	std::cin >> n >> M;
	for (maxn i = 0; i < n; i++)
		std::cin >> a[i];
}


void Adjust(const maxa x) {
	//std::cout << mns << ' ' << x << '\n';
	if (!mx.empty()) {
		do {
			mns += mx.top();
			mn.push(mx.top());
			mx.pop();
		} while (mns < x);
	}

	while (!mn.empty() && mns - mn.top() >= x) {
		mns -= mn.top();
		mx.push(mn.top());
		mn.pop();
	}
	//std::cout << mx.size() << ' ' << mn.size() << ' ' << mns << '\n';
}


void Process() {
	mns = 0;
	maxa sum = 0;

	for (maxn i = 0; i < n; i++) {
		sum += a[i];
		Adjust(sum - M);
		std::cout << mn.size() << ' ';
		mx.push(a[i]);
	}
}
		

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}