// AC UVa
#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 22
#define minA (maxa)(-30000000000)

typedef int maxn;
typedef long long maxa;

maxn n, A, B, C;
maxa box[maxN][maxN][maxN], sum[maxN][maxN], mxs[maxN][maxN][maxN][maxN], res; // A B C


void Prepare() {
	std::cin >> A >> B >> C;

	for (maxn a = 1; a <= A; a++) 
		for (maxn b = 1; b <= B; b++) 
			for (maxn c = 1; c <= C; c++) 
				std::cin >> box[a][b][c];

	for (maxn b1 = 1; b1 <= B; b1++) 
		for (maxn c1 = 1; c1 <= C; c1++) 
			for (maxn b2 = b1; b2 <= B; b2++) 
				for (maxn c2 = c1; c2 <= C; c2++) 
					mxs[b1][c1][b2][c2] = 0;
}


void MakeSum(const maxn A) {
	for (maxn b = 1; b <= B; b++) {
		for (maxn c = 1; c <= C; c++) {
			sum[b][c] = sum[b][c - 1] + sum[b - 1][c] - sum[b - 1][c - 1] + box[A][b][c];
			}
	}
}


maxa getSum(const maxn uli, const maxn ulj, const maxn dri, const maxn drj) {
	return sum[dri][drj] - sum[dri][ulj - 1] - sum[uli - 1][drj] + sum[uli - 1][ulj - 1];
}


void Process() {
	res = minA;
	
	for (maxn a = 1; a <= A; a++) {
		MakeSum(a);

		for (maxn b1 = 1; b1 <= B; b1++) {
			for (maxn c1 = 1; c1 <= C; c1++) {
				for (maxn b2 = b1; b2 <= B; b2++) {
					for (maxn c2 = c1; c2 <= C; c2++) {
						mxs[b1][c1][b2][c2] = std::max(mxs[b1][c1][b2][c2], (maxa)0) + getSum(b1, c1, b2, c2);
						res = std::max(res, mxs[b1][c1][b2][c2]);
					}
				}
			}
		}
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;
	
	while (--q) {
		Prepare();
		Process();
		std::cout << res << "\n\n";
	}

	Prepare();
	Process();
	std::cout << res << "\n";
}