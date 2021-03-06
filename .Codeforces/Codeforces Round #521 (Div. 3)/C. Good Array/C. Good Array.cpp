// AC
#include "pch.h"
#include <iostream>

int n;
int a[200001], re[200001], max, max2;
long long t;

void Prepare() {

	std::cin >> n >> a[0] >> a[1];
	t = a[0] + a[1];

	bool p = a[1] > a[0];
	max = p;
	max2 = !p;

	for (int i = 2; i < n; i++) {
		std::cin >> a[i];
		t += a[i];

		if (a[max] < a[i]) {
			max2 = max;
			max = i;
		}
		else if (a[max2] < a[i]) max2 = i;
	}
}

int main() {
	Prepare();

	int cnt = 0;

	for (int i = 0; i < max; i++) {
		if (t - a[i] - a[max] == a[max]) {
			re[cnt++] = i + 1;
		}
	}

	for (int i = max + 1; i < n; i++) {
		if (t - a[i] - a[max] == a[max]) {
			re[cnt++] = i + 1;
		}
	}

	if (t - a[max2] - a[max] == a[max2]) {
		re[cnt++] = max + 1;
	}

	std::cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) std::cout << re[i] << ' ';
}
