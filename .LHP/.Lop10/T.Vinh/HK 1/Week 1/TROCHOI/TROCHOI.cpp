// full test

#include "pch.h";
#include <iostream>


unsigned long a[2][100001], re[100001], n, s, k;

void input() {
	std::cin >> n >> s >> k;
	for (int i = 0; i < s; i++) a[0][i] = i + 1;
}



void process() {
	unsigned long len = s, count = 0, k_th = k, p = 1;

	while (len > 0) {
		p = 1 - p;
		int len_2 = 0;
		for (int i = 0; i < len; i++) { 
			k_th = (k_th + 1) % (k + 1);
			if (k_th == 0) {
				count = (count + 1) % n;
				re[a[p][i]] = count == 0 ? 1 : 0;
				// re[a[p][i]] = (count = (count + 1) % n) == 0 ? 1 : 0;
			}
			else a[1 - p][len_2++] = a[p][i];
		}
		len = len_2;
	}

	for (int i = 1; i <= s; i++)
		if (re[i] == 1) std::cout << i << "\n";
}


int main() {
	input();
	if ((n < 2) || (n > 100) || (s < n) || (s > 100000) || (k > 15)) {
		std::cout << "So khong hop le";
		return 0;
	}
	process();
}