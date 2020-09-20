#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100002

typedef long maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], f[maxN][4];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i], f[i][0] = 1;
	f[n][0] = 1;
}


void Process() {
	for (maxn k = 1; k <= 3; k++) 
		for (maxn i = n - 1; i >= 0; i--) 
			f[i][k] = a[i] * f[i + 1][k - 1] + f[i + 1][k];
	
	std::cout << f[0][3];
}


int main() {
	//freopen("zoo.inp", "r", stdin);
	//freopen("zoo.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}