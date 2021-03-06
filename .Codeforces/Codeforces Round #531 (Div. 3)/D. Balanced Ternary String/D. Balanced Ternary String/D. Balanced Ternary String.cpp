#include "pch.h"
#include <iostream>

#define maxN 300001
#define maxC 4
 
typedef long maxn;
typedef int maxa;

maxn cnt[maxC], cur[maxC];
maxn n, l;
maxa a[maxN];


void Prepare() {
	std::cin >> n;
	l = n / 3;

	for (maxn i = 0; i < n; i++) {
		char c;
		std::cin >> c;

		a[i] = c - 48;
		cnt[a[i]]++;
	}
}


maxa Lmin() {
	return cnt[0] < l ? 0 : cnt[1] < l ? 1 : cnt[2] < l ? 2 : -1;
}


void Process() {

	maxa tmp = Lmin();
	for (maxn i = 0; i < n && tmp != -1; i++) {
		cur[a[i]]++;
		if (cnt[a[i]] <= l || (tmp > a[i] && cur[a[i]] <= l)) continue;

		cnt[a[i]]--;
		cur[a[i]]--;

		a[i] = tmp;

		cnt[a[i]]++;
		cur[a[i]]++;

		tmp = Lmin();
	}
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Prepare();
	Process();
	for (maxn i = 0; i < n; i++) std::cout << a[i];
}