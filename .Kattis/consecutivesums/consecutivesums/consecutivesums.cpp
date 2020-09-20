// AC Kattis
#include <iostream>
#include <algorithm>

typedef long long maxa;

maxa a;


maxa Process() {
	maxa st = 0;

	for (maxa i = 1; i * i <= a; i++) {
		if (a % i != 0) continue;

		if (i != 1 && i & 1) st = std::max(st, (a / i) - (i / 2));
		else if ((a / i) & 1) st = std::max(st, ((a / i) / 2) - i + 1);

		if (a / i != 1 && (a / i) & 1) st = std::max(st, i - ((a / i) / 2));
		else if (i & 1) st = std::max(st, (i / 2) - (a / i) + 1);
	}
	if (!st) return 0;

	std::cout << a << " = ";
	bool p = 0;
	while (a) {
		if (p) std::cout << " + "; p = 1;
		std::cout << st, a -= st, ++st;
	}
	std::cout << '\n';
	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		std::cin >> a;
		if (!Process()) std::cout << "IMPOSSIBLE\n";
	}
}