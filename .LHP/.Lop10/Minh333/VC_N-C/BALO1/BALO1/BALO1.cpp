#include "pch.h"
#include <iostream>
#include <algorithm>

#define max 51

typedef int maxa;
typedef unsigned int maxn;

maxa a[max];
maxn n;
unsigned long long S, W, re;

void Prepare() {
	std::cin >> n >> W;
	for (maxn i = 0; i < n; i++)
		std::cin >> a[i];
}


void Try(maxn i) {

	if (S == W) {
		re++;
		return;
	}
	for (i; i < n; i++) {
		S += a[i];
		if (S <= W) Try(i + 1);
		S -= a[i];
	}
	/*while (i < n && S + a[i] <= W) {
		S += a[i];
		Try(i + 1);
		S -= a[i];
		i++;
	}*/

}

int main() {
	Prepare();
	//std::sort(a, a + n);
	Try(0);
	std::cout << re;
}