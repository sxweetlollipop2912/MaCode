#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define maxN 200001
#define maxA ('9' + 1)
#define minA ('0' - 1)

typedef long maxn;
typedef char maxa;
typedef std::string str;

maxn n;
str a;
maxa mn2, mx2;
bool one[maxN];


void Prepare() {
	std::cin >> n >> a;
	std::fill(one, one + n, 0);
}


bool Process() {
	std::vector <maxn> stack;
	mn2 = maxA;

	for (maxn i = 0; i < n; i++) {
		while (!stack.empty() && a[stack.back()] > a[i]) {
			one[stack.back()] = 0;
			mn2 = std::min(mn2, a[stack.back()]);
			stack.pop_back();
		}
		stack.push_back(i); one[i] = 1;
	}
	while (a[stack.back()] > mn2) {
		one[stack.back()] = 0;
		stack.pop_back();
	}

	for (maxn i = 0; i < n; i++) {
		if (one[i]) continue;
		if (a[i] < mn2) return 0;
		mn2 = a[i];
	}

	for (maxn i = 0; i < n; i++) {
		if (one[i]) std::cout << '1';
		else std::cout << '2';
	}
	std::cout << '\n';

	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t;
	std::cin >> t;

	while (t--) {
		Prepare();
		if (!Process()) std::cout << "-\n";
	}
}