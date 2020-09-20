// AC
#include <iostream>
#include <algorithm>
#include <cstdio>

//#define maxA (1 << 32)
#define left first
#define right second
#define isOn(b, i) (((b) >> (i)) & 1)

typedef long long maxa;
typedef std::pair <maxa, maxa> r_t;

maxa n, res;
r_t range;


void Prepare() {
	std::cin >> n >> range.left >> range.right;
}


void Try(const r_t ran, const int x) {
	//std::cout << ran.left << ' ' << ran.right << '\n';
	if (ran.left > ran.right) return;
	if (x == -1) {
		if ((res | n) < (ran.left | n)) res = ran.left;
		else if ((res | n) == (ran.left | n)) res = std::min(res, ran.left);
		return;
	}

	maxa x1 = (maxa)1 << x;
	if (((ran.left / x1) & 1) == isOn(n, x)) {
		if (ran.right - ran.left + 1 <= x1 && ((ran.right / x1) & 1) == isOn(n, x)) Try(ran, x - 1);
		else Try(r_t(x1 * ((ran.left / x1) + 1), std::min(ran.right, x1 * ((ran.left / x1) + 1) + x1 - 1)), x - 1);
	}
	else {
		Try(r_t(ran.left, std::min(ran.right, x1 * ((ran.left / x1) + 1) - 1)), x - 1);
		Try(r_t(x1 * (ran.left / x1 + 2), std::min(ran.right, x1 * (ran.left / x1 + 2) + x1 - 1)), x - 1);
	}
}


void Process() {
	res = range.left;
	Try(range, 31);
	std::cout << res << '\n';
}


int main() {
	//freopen("10718.inp", "r", stdin);
	//freopen("10718.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n >> range.left>> range.right) Process();
}