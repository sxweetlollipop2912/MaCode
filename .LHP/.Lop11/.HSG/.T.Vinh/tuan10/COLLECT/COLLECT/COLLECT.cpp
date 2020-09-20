#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 10001
//#define maxT 48
#define profit second
#define leave first

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> info;

maxn n, T;
info a[maxN];
maxa res;
std::priority_queue <maxa, std::vector <maxa> > pq;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i].profit >> a[i].leave, T = std::max(a[i].leave, T);
	std::sort(a, a + n);
}


void Process() {
	res = 0;
	maxn ai = n - 1;

	for (maxn t = T; t >= 0; t--) {
		while (ai >= 0 && a[ai].leave > t) 
			pq.push(a[ai].profit); --ai;

		if (pq.empty()) continue;
		res += pq.top();
		pq.pop();
	}

	std::cout << res;
}


int main() {
	freopen("collect.inp", "r", stdin);
	freopen("collect.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}