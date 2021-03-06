// AC
#include "pch.h"
#include <iostream>

unsigned long long sum, money, a[2][200001];
unsigned int n;
bool p;

void Prepare() {
	std::cin >> n >> money;
	for (int i = 0; i < n; i++) 
		std::cin >> a[p][i];
	sum = 1;
}


bool Mark() {
	if (money == 0) return 0;
	sum = 0;
	p = 1 - p;
	unsigned long long k = 0;

	for (int i = 0; i < n; i++) {
		
		sum += a[1 - p][i];
		
		if (sum <= money) 
			a[p][k++] = a[1 - p][i];
		else 
			sum -= a[1 - p][i];
	}
	n = k;
	return sum > 0;
}


int main() {
	Prepare();

	unsigned long long re = 0;
	
	while (Mark()) {
		re += n * (money / sum);
		money %= sum;
	}

	std::cout << re;
}