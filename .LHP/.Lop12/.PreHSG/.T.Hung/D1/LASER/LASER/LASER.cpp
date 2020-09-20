#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 52
#define maxK 101
#define maxC 259

typedef int maxn;

struct maxa {
	int Num[maxC];
	int Len;

	maxa() {
		std::fill(Num, Num + maxC, 0);
		Len = 1;
	}
	maxa(int x) {
		std::fill(Num, Num + maxC, 0);
		Len = 0;
		for (int i = 0; x != 0; i++)
			Num[i] = x % 10, x /= 10, ++Len;
		Len = std::max(Len, 1);
	}
	maxa(long long x) {
		std::fill(Num, Num + maxC, 0);
		Len = 0;
		for (int i = 0; x != 0; i++)
			Num[i] = x % 10, x /= 10, ++Len;
		Len = std::max(Len, 1);
	}
};

maxn n, K;
maxa f[maxN][maxK], res;


void Prepare() {
	std::cin >> n >> K;
}


void Output(const maxa& a) {
	for (int i = a.Len - 1; i >= 0; i--)
		std::cout << a.Num[i];
}


void Trim(maxa& a) {
	while (a.Len != 1 && a.Num[a.Len - 1] == 0) 
		--a.Len;
}


void Add(maxa &a, const maxa &b) { // a += b
	a.Len = std::max(a.Len, b.Len);

	for (int i = 0; i < a.Len; i++) {
		a.Num[i] = a.Num[i] + b.Num[i];
		if (a.Num[i] > 9) {
			if (i + 1 == a.Len) ++a.Len;
			a.Num[i + 1] += a.Num[i] / 10;
			a.Num[i] %= 10;
		}
	}
	Trim(a);
}


void Multi(const maxa &a, const maxa &b, maxa &re) { // a*= b
	re.Len = (a.Len - 1) + (b.Len - 1) + 1;

	for (int i = 0; i < a.Len; i++) for (int j = 0; j < b.Len; j++) {
		re.Num[i + j] += a.Num[i] * b.Num[j];
		if (re.Num[i + j] > 9) {
			if (i + j + 1 == re.Len) ++re.Len;
			re.Num[i + j + 1] += re.Num[i + j] / 10;
			re.Num[i + j] %= 10;
		}
	}
	while (re.Num[re.Len - 1] > 9) {
		re.Num[re.Len] += re.Num[re.Len - 1] / 10;
		re.Num[re.Len - 1] %= 10;
		++re.Len;
	}
	Trim(re);
}


maxa Process() {
	if (n == 0) return 0;
	if (n == 1) return K == 1 ? 1 : 0;
	if (n == 2) return K == 2 ? 4 : K == 1 ? 4 : 0;

	f[1][0] = f[2][0] = 1, f[1][1] = 2, f[2][1] = 4, f[2][2] = 2;
	maxa tmp = 0;

	for (maxn i = 3, L = i * 2; i < n; i++, L = i * 2) {
		f[i][0] = 1;
		for (maxn k = 1; k <= K; k++) {
			f[i][k] = f[i - 2][k];
			tmp = 0;
			Multi(f[i - 2][k - 1], (maxa)std::max(0, (L - 2 * (k - 1))), tmp);
			Add(f[i][k], tmp);

			if (k == 1) continue;

			maxn L2 = std::max(0, (L - 2 * (k - 2)));
			tmp = 0;
			Multi(f[i - 2][k - 2], (maxa)((L2 / 2) * (L2 / 2 - 1)), tmp);
			Add(f[i][k], tmp);
		}
	}
	f[n][0] = 1;
	Multi(f[n][0], f[n - 1][K], res);

	res = 0;
	for (maxn k = 1, L = n; k <= K; k++) {
		f[n][k] = f[n - 2][k];

		tmp = 0;
		Multi(f[n - 2][k - 1], (maxa)std::max(0, (L - (k - 1))), tmp);
		Add(f[n][k], tmp);

		tmp = 0;
		Multi(f[n][k], f[n - 1][K - k], tmp);
		Add(res, tmp);
	}

	return res;
}


int main() {
	//freopen("laser.inp", "r", stdin);
	//freopen("laser.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Output(Process());
}