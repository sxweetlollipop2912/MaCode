//DONE
//file:///D:/Music/FPC/fpc/TopCoder%20Statistics%20-%20Problem%20Statement.html
#include "pch.h"
#include <iostream>

int h[50], b[50], w[50], s[50], n;
bool check[50][50], checkSure = false;

void input() {
	std::cin >> n;
	for (int i = 0; i < n; i++) std::cin >> h[i];
	for (int i = 0; i < n; i++) std::cin >> b[i];
	for (int i = 0; i < n; i++) std::cin >> w[i];
}

int isAtFront(int i, int j) {
	checkSure = ((b[i] >= b[j]) && (b[i] <= w[j])) || ((b[j] >= b[i]) && (b[j] <= w[i]));
	return checkSure * (h[i] > h[j]);
}

void fillCheckArr() {
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			check[i][j] = isAtFront(i, j);
			check[j][i] = checkSure * !check[i][j];
			s[i] += check[i][j];
			s[j] += check[j][i];
		}
}


int fitIndex() {
	int re = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != 0) continue;
		if ((h[i] > h[re]) || (s[re] != 0)) re = i;
	}
	s[re] = -1;
	return re;
}


int main() {
	input();
	fillCheckArr();
	for (int i = 0; i < n; i++) {
		int hi = fitIndex();
		std::cout << h[hi] << " ";
		for (int j = 0; j < n; j++)
			s[j] -= check[j][hi];
	}
}