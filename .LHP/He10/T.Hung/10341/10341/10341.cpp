// AC UVa
#include "pch.h"
#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>

#define minX ((maxa)0)
#define maxX ((maxa)1)
#define epsilon ((maxa)(0.00001))

typedef double maxa;

maxa p, q, r, s, t, u;


void Prepare() {
	std::cin >> p >> q >> r >> s >> t >> u;
}


bool mover(const maxa x) {
	//std::cout << x << ' ' << p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u << '\n';
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u < 0;
}


bool check(const maxa x) {
	//std::cout << x << ' ' << p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u << '\n';
	return abs(p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u) < epsilon;
}


void Process() {
	maxa l = minX, r = maxX;
	
	maxa m = (l + r) / (maxa)2;
	while (l != m && r != m) {
		//std::cout << m << ' ';
		if (mover(m)) r = m;
		else l = m;
		//std::cout << l << ' ' << r << '\n';
		m = (l + r) / (maxa)2;
	}
	
	//std::cout << m << ' ' << p * exp(-m) + q * sin(m) + r * cos(m) + s * tan(m) + t * m*m + u << '\n';
	if (check(m)) std::cout << m << '\n';
	else std::cout << "No solution\n";
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cout << std::fixed;
	std::cout << std::setprecision(4);

	while (std::cin >> p >> q >> r >> s >> t >> u) {
		Process();
	}
}