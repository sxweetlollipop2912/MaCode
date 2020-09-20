#include "pch.h"
#include <iostream>
#include <fstream>

int n;
bool a[200001];

void Prepare() {
	//freopen("PREDNEXTBR.inp", "r", stdin);
	//freopen("PREDNEXTBR.out", "w", stdout);
	std::cin >> n;
	n *= 2;
	for (int i = 0; i < n; i++) {
		char c;
		std::cin >> c;
		a[i] = c == '(' ? 0 : 1;
	}
}

void swap(int i, int j) {
	bool temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


char Ch(bool a) {
	return a == 1 ? ')' : '(';
}


void Prev() {
	int one = 1, zero = 0;

	int ii;
	for (ii = n - 2; ii >= 0; ii--) {
		one += a[ii];
		zero += 1 - a[ii];
		if (!a[ii + 1] && a[ii]) break;
	}

	if (ii < 0) {
		std::cout << -1;
		return;
	}

	swap(ii, ii + 1);
	zero--;

	for (int i = 0; i <= ii; i++) std::cout << Ch(a[i]);
	for (int i = 0; i < one - zero; i++) std::cout << ')';
	for (int i = 0; i < zero; i++) std::cout << "()";

	swap(ii, ii + 1);
}

void Next() {
	int one = 0, zero = 0;

	int ii;
	for (ii = n - 1; ii > 0; ii--) {
		one += a[ii];
		zero += 1 - a[ii];
		if (!a[ii - 1] && (one - zero >= 2)) break;
	}

	if (ii == 0) {
		std::cout << -1;
		return;
	}

	swap(ii, ii - 1);
	zero++; one--;

	for (int i = 0; i < ii; i++) std::cout << Ch(a[i]);
	for (int i = 0; i < zero; i++) std::cout << '(';
	for (int i = 0; i < one; i++) std::cout << ')';

	swap(ii, ii - 1);
}


int main() {
	Prepare();
	Prev();
	std::cout << '\n';
	Next();
}
