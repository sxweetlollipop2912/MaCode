//DONE
//http://codeforces.com/contest/1058/problem/C
#include "pch.h"
#include <iostream>

int a[100], n, sum[101], re[451], t, max;
bool tag[451], result = false;


void Prepare() {
	std::cin >> n;
	t = 0;
	
	char s[101];
	std::cin.getline(s, 1, '\n');
	std::cin.getline(s, n + 1, '\n');
	
	for (int i = 0, j = 0; j < n; i++) {
		n--;
		if (s[i] == '0') continue;
		n++;
		t += (a[j++] = s[i] - 48);
	}
	
	for (int i = 1; i <= t / 2; i++)
		if (t%i == 0) {
			tag[i] = 1;
			max = i;
			re[i] = 0;
		}
		else tag[i] = 0;
}

void Operate(int x) {
	for (int i = 1; i <= x + 1; i++) {
		sum[i] += a[x];
		if ((sum[i] - a[x] == -1) || (sum[i] > max)) {
			sum[i] = -1;
			continue;
		}
		
		if ((tag[sum[i]] == 1) && (i == re[sum[i]] + 1)) re[sum[i]] = x + 1;
		
		if (re[sum[i]] == n) {
			result = true;
			return;
		}
	}
}


int main() {
	Prepare();
	if (t == 0) result = true;
	else for (int i = 0; i < n; i++) Operate(i);
	
	if (result) std::cout << "YES";
	else std::cout << "NO";
}