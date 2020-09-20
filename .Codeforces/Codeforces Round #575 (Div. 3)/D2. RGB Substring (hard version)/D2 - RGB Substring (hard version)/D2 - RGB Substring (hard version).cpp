#include <iostream>
#include <algorithm>

#define maxN 200002
#define R 0
#define G 1
#define B 2

typedef long maxn;

maxn n, k, f[maxN][3], res;


void Prepare() {
	std::cin >> n >> k;
}


int Read() {
	char c;
	std::cin >> c;
	return c == 'R' ? R : c == 'G' ? G : B;
}


int start(const int col) {
	return (col + 3 - (k % 3)) % 3;
}


void Process() {
	// R G B R
	for (maxn i = 1; i < k; i++) {
		int a = Read();
		f[i][R] = f[i - 1][B] + (a != R);
		f[i][G] = f[i - 1][R] + (a != G);
		f[i][B] = f[i - 1][G] + (a != B);
	}

	res = n;
	for (maxn i = k; i <= n; i++) {
		int a = Read();
		f[i][R] = f[i - 1][B] + (a != R);
		res = std::min(res, f[i][R] - f[i - k][start(R)]);

		f[i][G] = f[i - 1][R] + (a != G);
		res = std::min(res, f[i][G] - f[i - k][start(G)]);

		f[i][B] = f[i - 1][G] + (a != B);
		res = std::min(res, f[i][B] - f[i - k][start(B)]);
	}

	std::cout << res << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long q;
	std::cin >> q;

	while (q--) {
		Prepare();
		Process();
	}
}