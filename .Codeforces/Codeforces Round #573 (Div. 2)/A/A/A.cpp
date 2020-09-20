#include <iostream>
#include <algorithm>

#define maxN 100001

typedef long maxn;
typedef long long maxa;

maxn n;
maxa a[maxN];
bool pair;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) 
		std::cin >> a[i];

	std::sort(a, a + n);
}


bool Process() {
	pair = 0;
	for (maxn i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) continue;
		if (!a[i] || pair || (i > 1 && a[i - 2] + 1 == a[i])) return 0;
		pair = 1, --a[i - 1];
	}

	maxa move = 0;
	for (maxn i = 0; i < n; i++) 
		move += a[i] - i;

	return pair ^ (move % 2);
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (Process()) std::cout << "sjfnb";
	else std::cout << "cslnb";
}