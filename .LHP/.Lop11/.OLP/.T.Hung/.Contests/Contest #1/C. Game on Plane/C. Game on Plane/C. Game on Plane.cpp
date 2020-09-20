#include <iostream>
#include <algorithm>

#define maxN 5002
#define N 5000

typedef int maxq, maxn;

bool f[maxN];


void Process() {
	f[0] = f[1] = 0;
	
	for (maxn n = 2; n <= N; n++) for (maxn i = 0; i <= n - 2; i++) f[n] |= (f[i] ^ f[n - 2 - i]);

	for (maxn i = 0; i <= 50; i++) std::cout << i << ' ' << f[i] << '\n';
	//for (maxn i = 3; i <= N; i++) if (lose(i)) std::cout << i << ' ';

	maxq q; std::cin >> q;
	while (q--) {
		maxn n; std::cin >> n;
		if (f[n]) std::cout << "First\n";
		else std::cout << "Second\n";
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Process();
}