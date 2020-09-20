#include <iostream>
#include <algorithm>

typedef long long maxa;

maxa a[4], p;


void Prepare() {
	std::cin >> a[0] >> a[1] >> a[2] >> a[3] >> p;
}


maxa gcd(maxa a, maxa b) {
	maxa tmp;
	while (b) tmp = b, b = a % b, a = tmp;
	return a;
}


void Process() {
	maxa LCM = a[0] * a[1] / gcd(a[0], a[1]); LCM = LCM * a[2] / gcd(LCM, a[2]); LCM = LCM * a[3] / gcd(LCM, a[3]);
	maxa x = LCM;
	while ((x + 1) % p != 0) x += LCM;
	std::cout << x + 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}