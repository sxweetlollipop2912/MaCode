// n = 10 -> less than 1s || n = 11 -> approx. 6s on lap
#include "pch.h"
#include <iostream>
#include <fstream>

#define maxn 12

int a[maxn], f[maxn + 1][maxn + 1], re[maxn], t[maxn], n, min;


void swap(int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


void CheckMin() {
	if (t[n] >= min) return;
	min = t[n];
	for (int i = 0; i < n; i++) re[i] = a[i];
}


void Prepare() {
	//freopen("TOUR.inp", "r", stdin);
	//freopen("TOUR.out", "w", stdout);
	std::cin >> n;

	for (int i = 0; i < n; i++)
		std::cin >> f[0][i + 1] >> f[i + 1][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> f[i + 1][j + 1];

	a[0] = 1;
	t[0] = f[0][a[0]];
	for (int i = 1; i < n; i++) {
		a[i] = i + 1;
		t[i] = t[i - 1] + f[a[i - 1]][a[i]];
	}
	t[n] = t[n - 1] + f[a[n - 1]][0];
	
	CheckMin();
}


bool Next() {

	int ii;
	for (ii = n - 2; ii >= 0; ii--)
		if (a[ii] < a[ii + 1]) break;

	if (ii < 0) return 0;

	int jj;
	for (jj = n - 1; jj > ii; jj--)
		if (a[jj] > a[ii]) break;

	swap(ii, jj);
	if (ii > 0) t[ii] = t[ii - 1] + f[a[ii - 1]][a[ii]]; 
	else t[ii] = f[0][a[ii]];

	for (int i = ii + 1; i <= (n + ii) / 2; i++)
		swap(i, n - i + ii);

	for (int i = ii + 1; i < n; i++) 
		t[i] = t[i - 1] + f[a[i - 1]][a[i]];

	t[n] = t[n - 1] + f[a[n - 1]][0];
	
	CheckMin();
	return 1;
}



int main() {
	Prepare();
	min = maxn * 1000 + 1;
	while (Next());
	std::cout << min << '\n';
	for (int i = 0; i < n; i++) std::cout << re[i] << ' ';
}
