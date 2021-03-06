// 6/10 test

#include "pch.h"
#include <iostream>
#include <string>
#include <regex>

int n, count, a[57], b[57];
bool c[57];
long k;
std::string s, p;

void input() {
	std::cin >> n >> k;
	if ((n < 1) | (n > 4000) | (k < n) | (k > 3000000)) throw "Khong hop le";

	std::cin >> s >> p;
	if ((s.size() != n) | (p.size() != k)) throw "Khong hop le";

	std::regex e("[A-za-z]+", std::regex_constants::extended);
	if (!std::regex_match(s + p, e)) throw "Khong hop le";

	std::fill(a, a + 57, 0);

	for (int i = 0; i < n; i++)
		count += a[s[i] - 57]++ == 0 ? 1 : 0;
}


int main() {
	input();

	int kt = 0;
	std::fill(b, b + 57, 0);
	std::fill(c, c + 57, 0);

	for (int i = 0; i < n; i++) {
		int j = p[i] - 57;
		kt -= c[j];
		c[j] = (a[j] > 0) && (++b[j] == a[j]) ? 1 : 0;
		kt += c[j];
	}

	int re = kt == count ? 1 : 0;

	for (int i = 1; i < k - n + 1; i++) {
		int j = p[i + n - 1] - 57;
		int id = p[i - 1] - 57;
		kt = kt - c[j] - c[id];
		c[j] = (a[j] > 0) && (++b[j] == a[j]) ? 1 : 0;
		c[id] = (a[id] > 0) && (--b[id] == a[id]) ? 1 : 0;
		kt += c[j] + c[id];
		if (kt == count) re++;
	}

	std::cout << re;
}
