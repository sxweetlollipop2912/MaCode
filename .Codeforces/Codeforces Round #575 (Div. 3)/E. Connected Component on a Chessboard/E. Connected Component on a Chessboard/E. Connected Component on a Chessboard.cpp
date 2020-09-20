#include <iostream>
#include <algorithm>

#define maxN 100001

typedef long maxn, maxa;

maxn b, w;


void Prepare() {
	std::cin >> b >> w;
}


void Write(maxa row, maxa i, maxn q) {
	while (q--) 
		std::cout << row << ' ' << i << '\n', i += 2;
}


bool Process() {
	if (w < ((b - 1 + 3 - 1) / 3)) return 0;
	if (b < ((w - 1 + 3 - 1) / 3)) return 0;

	std::cout << "YES\n";

	maxn mn = std::min(b, w);

	Write(2, 1 + (b < w), mn + (w != b));
	Write(2, 2 + (b < w), mn);

	b = std::max(b - mn - 1, (maxn)0), w = std::max(w - mn - 1, (maxn)0);
	Write(1, 2, std::min(b, mn));
	Write(1, 3, std::min(w, mn));

	b -= std::min(b, mn), w -= std::min(w, mn);
	Write(3, 2, b);
	Write(3, 3, w);
	
	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long q;
	std::cin >> q;

	while (q--) {
		Prepare();
		if (!Process()) std::cout << "NO\n";
	}
}