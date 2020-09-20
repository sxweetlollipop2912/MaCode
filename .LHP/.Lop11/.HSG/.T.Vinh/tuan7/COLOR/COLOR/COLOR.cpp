#include <iostream>
#include <cstdio>

#define maxN 33
#define REQ1 21 // 10101
#define REQ2 5  // 101
#define isOn(b, i) (((b) >> (i)) & 1)

typedef long long t;

t m, n;


void Prepare() {
	std::cin >> m >> n;
}


bool check(const t b, const t i, const bool opt) {
	return (opt || i < 5 || (((~b) & REQ1) != REQ1)) && (i < 3 || ((b & REQ2) != REQ2));
}


bool Check(const t b) {
	t p[2] = { 0,b << 1 };

	for (t r = 1; r < m; r++) {
		t b1 = 0;
		for (t i = 1; i <= n; i++) {
			b1 <<= 1;
			if (!isOn(p[r & 1], i - 1) && !isOn(p[r & 1], i + 1) && !isOn(p[!(r & 1)], i)) ++b1;
			if (!check(b1, i, r == m - 1)) return 0;
		}
		p[!(r & 1)] = b1 << 1;
	}
	for(t i = 1; i <= n; i++) 
		if (!isOn(p[m & 1], i - 1) && !isOn(p[m & 1], i + 1) && !isOn(p[!(m & 1)], i)) return 0;

	return 1;
}



t Try(const t b, const t i) {
	if (!check(b, i, m == 1)) return 0;
	if (i == n) return Check(b);
	return Try(b << 1, i + 1) + Try((b << 1) + 1, i + 1);
}


void Process() {
	std::cout << Try(0, 0);
}


int main() {
	//freopen("color.inp", "r", stdin);
	//freopen("color.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}