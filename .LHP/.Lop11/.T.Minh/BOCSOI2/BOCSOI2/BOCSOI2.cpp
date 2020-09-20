#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bitset>

#define maxA 10002
#define N 10000

typedef int maxa;
typedef std::bitset <maxA> maxb;

maxa a, b, pos[maxA];
maxb r;


void Process() {
	for (maxa y = 0, x = 0; y <= N && x <= N; y++) {
		pos[y] = x, pos[x] = y, r.set(x), r.set(y);
		while (x <= N && y < N && r[x]) ++x, ++y;
	}

	while (std::cin >> a >> b) {
		if (a == b) std::cout << a << ' ' << b;
		else if (pos[a] && pos[a] < b) std::cout << "0 " << b - pos[a];
		else if (pos[b] && pos[b] < a) std::cout << a - pos[b] << " 0";
		else {
			maxa a1 = a, b1 = b;
			while (a1 != 0 && b1 != 0 && pos[b1] != a1) --a1, --b1;
			if (a1 && b1) std::cout << a - a1 << ' ' << b - b1;
			else std::cout << "0 0";
		}
		std::cout << '\n';
	}
}


int main() {
	//freopen("bocsoi2.inp", "r", stdin);
	//freopen("bocsoi2.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Process();
}