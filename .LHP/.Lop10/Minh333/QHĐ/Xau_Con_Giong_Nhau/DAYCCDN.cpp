#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


#define maxN 5002
#define maxA 256

typedef int maxn, maxa;

maxa a[maxN], b[maxN];
std::vector <maxn> cb;
maxn m, n, f[maxN][maxN];

void Prepare() {
	freopen("DAYCCDN.inp", "r", stdin);
	freopen("DAYCCDN.out", "w", stdout);
	std::cin >> m >> n;
	for (maxn i = 0; i < m; i++) std::cin >> a[i];
	for (maxn i = 0; i < n; i++) std::cin >> b[i];
}


int main() {
	Prepare();

	for (maxn i = m; i > 0; i--) {
		for (maxn j = n; j > 0; j--) {
			if (a[i - 1] == b[j - 1]) f[i][j] = f[i + 1][j + 1] + 1;
			else f[i][j] = std::max(f[i + 1][j], f[i][j + 1]);
		}
	}
	std::cout << f[1][1] << '\n';

	// Truy vet

    maxn re = f[1][1];
    maxn jj = 1;

    for(maxn i = 1; i <= m; i++) {
        for(maxn j = jj; j <= n; j++) {
            if (f[i][j] == re && f[i][j + 1] != f[i][j] && f[i + 1][j] != f[i][j]) {
                std::cout << i << ' ';
                cb.push_back(j);
                re--;
                jj = j + 1;
                break;
            }
        }
    }

    std::cout << '\n';
    for(maxn i = 0; i < cb.size(); i++) std::cout << cb[i] << ' ';
}
