#include <iostream>
#include <algorithm>
#include <cstdio>

//#define maxN 300001
#define maxC 600001
#define a(id) c[id]
#define b(id) c[n + (id)]
#define mid(n) ((n) / 2)

typedef long maxn;
typedef long long maxa;

maxn n;
maxa c[maxC], res;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a(i);
	for (maxn i = 0; i < n; i++) std::cin >> b(i);
}


void Process() {
	for (maxn i = 0; i < n; i++) a(i) -= abs(mid(n) - i), b(i) -= abs(mid(n) - i);
	std::sort(c, c + (n * 2));
	res = 0;
	for (maxn i = 0; i < 2 * n; i++) res += abs(c[i] - c[mid(2 * n)]);
	std::cout << res;
}


int main() {
	//freopen("dayso.inp", "r", stdin);
	//freopen("dayso.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}