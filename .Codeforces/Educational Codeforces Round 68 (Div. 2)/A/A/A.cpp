#include <iostream>
#include <algorithm>


bool Process(long n, long k) {
	if (k % 3 == 0) return (n % (k + 1)) % 3 != 0 || (n % (k + 1)) == k;
	return n % 3 != 0;
}

int main() {
	long t, n, k;
	std::cin >> t;

	while (t--) {
		std::cin >> n >> k;
		if (Process(n, k)) std::cout << "Alice\n";
		else std::cout << "Bob\n";
	}
}
