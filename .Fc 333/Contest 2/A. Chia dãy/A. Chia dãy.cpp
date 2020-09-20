#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 100001
#define maxA 1000000001

typedef long maxn, maxa;

maxn n;
maxa a[maxN];
std::vector <maxa> lis;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
	for (maxn i = n - 1; i >= 0; i--) {
		maxn pos = std::lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
		if (pos == lis.size()) lis.push_back(a[i]);
		else lis[pos] = a[i];
	}

	std::cout << lis.size();
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}