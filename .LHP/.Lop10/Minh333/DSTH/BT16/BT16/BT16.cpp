#include "pch.h"
#include <iostream>
#include <fstream>

int n, k, l = -1;
unsigned long long a[50000];

void Prepare() {
	//freopen("BT16.inp", "r", stdin);
	//freopen("BT16.out", "w", stdout);
	std::cin >> n >> k;
}


void Fill() {
	l++;
	//unsigned long long temp = 1;
	a[0] = 1;
	a[l + 1] = 1;
	std::cout << a[0] << " ";
	
	for (int i = l; i >= 1; i--) {
		a[i] = a[i] + a[i - 1];
		//a[i] = temp + a[i];
		//temp = a[i] - temp;
		std::cout << a[i] << " ";
	}
	
	std::cout << a[l + 1] << '\n';
}



int main() {
	Prepare();
	std::cout << "1\n";
	for (int i = 1; i <= n; i++) Fill();
	std::cout << "C(" << n << ", " << k << ") = " << a[k];
}