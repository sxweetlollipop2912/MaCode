#include <iostream>
#include <algorithm>
#include <set>

#define maxN 201

typedef int maxn, maxa;
typedef std::pair <maxa, maxa> pair;

maxn n;
maxa x[maxN], y[maxN];
std::set <pair> set;


maxa gcd(maxa a, maxa b) {
	while (b != 0) {
		maxa tmp = a % b;
		a = b, b = tmp;
	}
	return a;
}


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> x[i] >> y[i];
}


void Process() {
	for (maxn i = 0; i < n; i++) for (maxn j = i + 1; j < n; j++) {
		pair p; p.first = x[i] - x[j], p.second = y[i] - y[j];
		maxa g = gcd(p.first, p.second);
		p.first /= g, p.second /= g;
		set.insert(p);
	}

	std::cout << set.size();
}


int main() {
	//freopen("parallel.inp", "r", stdin);
	//freopen("parallel.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}