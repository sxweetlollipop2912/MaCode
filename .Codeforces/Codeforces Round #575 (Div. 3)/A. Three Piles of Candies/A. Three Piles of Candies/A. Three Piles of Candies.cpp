#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	while (q--) {
		long long a, b, c;
		std::cin >> a >> b >> c;
		std::cout << ((a + b + c) / 2) << '\n';
	}
}