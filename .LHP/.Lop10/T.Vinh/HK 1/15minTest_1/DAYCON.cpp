//DAYCON
// truong hop tat ca deu la so duong

#include <iostream>
#include <fstream>

int a[1000000], n;
long long m, t, re;

void Prepare() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) std::cin >> a[i];
}

int main() {
	freopen("DAYCON.inp", "r", stdin);
	freopen("DAYCON.out", "w", stdout);
	Prepare();

	int fw = 0, bw = 0, t = a[0];
	while (fw < n) {
		if (t > m) t -= a[bw++];
		else if ((t < m) && (++fw < n)) t += a[fw];
		else if (t == m) {
			re++;
			if (++fw < n) t += a[fw];
		}
	}

	std::cout << re;
}
