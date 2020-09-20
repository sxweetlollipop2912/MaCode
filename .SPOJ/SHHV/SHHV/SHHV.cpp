#include <iostream>
#include <algorithm>
#include <cstdio>

#pragma warning (disable:4996)

#define maxN 14

typedef unsigned long long t;

t n = -1, p[maxN];
bool a[maxN];


void Prepare() {
	t x;
	while (std::cin >> x) p[++n] = x;
}


t a_th_p(t x) {
	t n = 0;
	for (t i = 1; i < x; i++) n += (t)1 - a[i];
	a[x] = 1;
	return n;
}


t Position(t p[]) {
	std::fill(a, a + n + 1, 0);
	t re = 1, gt = 1;
	for (t i = 2; i < n; i++) gt *= (t)i;
	for (t i = 0; i < n - 2; i++) {
		re = re + a_th_p(p[i]) * gt;
		gt = gt / (n - i - (t)1);
	}
	re += a_th_p(p[n - 2]);
	return re;
}


t a_th_g(t n_th) {
	t re = 0, i = 0;
	while (re < n_th) re += (t)1 - a[++i];
	a[i] = 1;
	return i;
}


void Get(t n, t k) {
	std::fill(a, a + n + 1, 0);
	t gt = 1;
	for (t i = 2; i < n; i++) gt *= i;
	for (t i = 0; i < n - 1; i++) {
		std::cout << a_th_g(k / gt + (t)1) << " ";
		k = k % gt;
		gt = gt / (n - i - (t)1);
	}
	std::cout << a_th_g(1);
}


void Process() {
	std::cout << Position(p) << '\n';
	Get(n, p[n] - 1);
	//std::cout << n << ' ' << p[n] << '\n';
}


int main() {
	//freopen("shhv.inp", "r", stdin);
	Prepare();
	Process();
}