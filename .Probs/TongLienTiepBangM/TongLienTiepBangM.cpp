// max 10^9
//Optimize !!
// 42947470_413135532584341_8279765424116072448_n.png
#include "pch.h"
#include <iostream>

int m, A, B, max = 1, max_A;

void Prepare() {
	std::cin >> m;
	max_A = m;
}

bool check(int a) {
	bool c = false;
	// truong hop n2-n1+1 le
	if (((m / a) % 2 == 1) /*&& ((a & 1 == 0) || (a & 1 == 1))*/) { 
		c = true;          // ??????????                    
		A = a - m / (a * 2);
		if (A <= 0) return false;
		B = a + m / (a * 2);
	}
	//truong hop n2-n1+1 chan
	else if (a % 2 == 1) {
		c = true;
		A = (a - 1) / 2 - m / a + 1;
		if (A <= 0) return false;
		B = (a + 1) / 2 + m / a - 1;
	}
	return c;
}


int main() {
	Prepare();
	int i;
	int d = 0;
	for (i = 2; (i <= 78125) && (i <= m / 2); i++) {
		if ((m%i != 0) || (!check(i))) continue;
		d++;
		if (B - A + 1 > max) {
			max = B - A + 1;
			max_A = A;
			//break;
		}
	}
	//std::cout << max << '\n';
	//std::cout << i << '\n';
	std::cout << d << '\n';
	for (int i = max_A; i < max_A + max; i++) std::cout << i << " ";
}