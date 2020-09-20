#include "pch.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>

#define maxN 200001
#define maxK 200001
#define maxA 1000000001
//#define pqueue std::priority_queue <maxa, std::vector <maxa>, std::greater <maxn> >

typedef long long maxn, maxa;
typedef std::string str;
typedef std::priority_queue <maxa, std::vector <maxa>, std::greater <maxn> > pqueue;

maxn n, k;
maxa a[maxN], res;
pqueue pq;
str s;


void Empty() {
	pq = std::priority_queue <maxa, std::vector <maxa>, std::greater <maxn> >();
}


void Prepare() {
	std::cin >> n >> k;

	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i];
		res += a[i];
	}

	std::cin >> s;
	s = (char)(s[0] + 1) + s;
}


void Process() {
	//std::cout << res << ' ' << s << '\n';
	for (maxn i = 1; i <= n; i++) {
		if (s[i] != s[i - 1]) Empty();
		pq.push(a[i - 1]);

		if (pq.size() != k + 1) continue;
		
		res -= pq.top();
		//std::cout << i << ' ' << res << ' ' << pq.top() << ' ' << a[i - 1] << ' ' << s[i] << '\n';
		pq.pop();
	}
}


int main() {
	Prepare();
	Process();
	std::cout << res;
}