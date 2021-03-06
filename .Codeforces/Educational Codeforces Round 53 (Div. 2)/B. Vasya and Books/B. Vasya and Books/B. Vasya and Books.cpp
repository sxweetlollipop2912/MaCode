// AC
#include "pch.h"
#include <iostream>

int a[200001], n;


void Prepare() {
	std::cin >> n;
	int c;
	for (int i = 0; i < n; i++) {
		std::cin >> c;
		a[c] = i + 1;
	}
}


int main() {
	Prepare();

	int c, max = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> c;
		if (a[c] < max) std::cout << "0 ";
		else {
			std::cout << a[c] - max << ' ';
			max = a[c];
		}
	}
}

/*#include "pch.h"
#include <iostream>


const int N = int(2e5) + 9;

int n;
int a[N];
int b[N];
bool u[N];

int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}

	int pos = 0;
	for (int i = 0; i < n; ++i) {
		int x = b[i];
		if (u[x]) {
			std::cout << "0 ";
			continue;
		}

		int cnt = 0;
		while (true) {
			++cnt;
			u[a[pos]] = true;
			if (a[pos] == x) break;
			++pos;
		}

		++pos;
		std::cout << cnt << ' ';
	}

	puts("");
	return 0;
}*/