#include <iostream>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long n, k;
	std::string s;
	std::cin >> n >> k >> s;

	if (k == 0) std::cout << s;
	else if (n == 1) std::cout << "0";
	else {
		std::cout << "1";
		k -= s[0] != '1';
		for (long i = 1; i < n; i++) {
			if (k > 0) std::cout << "0";
			else std::cout << s[i];
			k -= s[i] != '0';
		}
	}
}