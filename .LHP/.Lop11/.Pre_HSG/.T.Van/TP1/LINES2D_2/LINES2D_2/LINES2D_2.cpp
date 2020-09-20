#include <iostream>
#include <algorithm>
#include <set>

#define maxN 100001

typedef long maxn, maxa;
typedef std::pair <maxa, maxa> pair;

maxn n;
std::set <pair> set;


maxa gcd(maxa a, maxa b) {
	while (b != 0) {
		maxa tmp = a % b;
		a = b, b = tmp;
	}
	return a;
}


void Process() {
	std::cin >> n;

	while (n--) {
		maxa a, b, c;
		std::cin >> a >> b >> c;

		maxa g = gcd(a, b);
		set.insert(pair(a / g, b / g));
	}

	std::cout << set.size();
}


int main() {
	freopen("lines2d.inp", "r", stdin);
	freopen("lines2d.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Process();
	//std::cout << '\n' << gcd(3, 0);
}