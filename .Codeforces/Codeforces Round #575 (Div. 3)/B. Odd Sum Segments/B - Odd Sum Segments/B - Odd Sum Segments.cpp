#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 200001

typedef long long maxn, maxa;


bool Process() {
	maxn n, k;
	std::cin >> n >> k;

	std::vector <maxa> res;
	maxa sum = 0;

	for (maxn i = 0; i < n; i++) {
		maxa a;
		std::cin >> a;

		sum += a;
		if (sum % 2 == 0) continue;

		res.push_back(i + 1);
		sum = 0;
	}

	if (res.size() < k || (res.size() - k) % 2 != 0) return 0;

	std::cout << "YES\n";
	for (maxn i = 0; i < k - 1; i++) std::cout << res[i] << ' ';
	std::cout << n << '\n';

	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long q;
	std::cin >> q;

	while (q--) 
		if (!Process()) std::cout << "NO\n";
}