#include <iostream>
#include <algorithm>
#include <cstdio>

#define N 2 

typedef int maxn;
typedef long long maxa;

struct Matrix { 
	maxa mat[N][N]; 
};

maxa n, m, MOD;


void Prepare() {
	std::cin >> n >> m;
}


Matrix matMul(Matrix a, Matrix b, maxa MOD) {
	Matrix re;
	for (maxn i = 0; i < N; i++) for (maxn j = 0; j < N; j++) {
		re.mat[i][j] = 0;
		for (maxn k = 0; k < N; k++) re.mat[i][j] = (re.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % MOD) % MOD;
	}
	return re;
}


Matrix matPow(Matrix a, maxa P, maxa MOD) {
	Matrix re = a, x = a;
	for (maxa p = P; p != 0; p >>= 1) {
		if (p & 1) re = matMul(re, x, MOD);
		x = matMul(x, x, MOD);
	}
	return re;
}


maxa fib(maxa P, maxa MOD) {
	Matrix m;
	m.mat[0][0] = m.mat[0][1] = m.mat[1][0] = 1;
	m.mat[1][1] = 0;
	return matPow(m, P, MOD).mat[1][1];
}



void Process() {
	std::cout << fib(n, (maxa)1 << m) << '\n';
}


int main() {
	freopen("10229.inp", "r", stdin);
	freopen("10229.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n >> m) {
		Process();
	}
}