// AC UVa
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

#define maxE 31702
#define E 31700
#define maxL 10002
#define L 10000

typedef long long maxa;

maxa l, r, res_num, res_div;
std::vector <maxa> prime;
std::bitset<maxE> p;


void Era() {
	p.set();
	p[0] = p[1] = 0;

	for (maxa i = 2; i <= E; i++) {
		if (!p[i]) continue;
		for (maxa j = i * i; j <= E; j += i) p[j] = 0;
		prime.push_back(i);
	}
}


maxa numDiv(maxa n) {
	maxa idx = 0, pr = prime[idx], re = 1;

	while (pr * pr <= n) {
		maxa pow = 0;
		while (n % pr == 0) n /= pr, ++pow;
		re *= (pow + 1);
		pr = prime[++idx];
	}

	if (n != 1) re *= 2;
	return re;
}


int main() {
	freopen("294.inp", "r", stdin);
	freopen("294.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Era();
	int q;
	std::cin >> q;

	while (q--) {
		std::cin >> l >> r;
		
		std::cout << "Between " << l << " and " << r << ", ";
		res_num = res_div = 0, --l;
		while (++l <= r) {
			maxa tmp = numDiv(l);
			if (tmp <= res_div) continue;
			res_num = l, res_div = tmp;
		}
		std::cout << res_num << " has a maximum of " << res_div << " divisors.\n";
	}
}