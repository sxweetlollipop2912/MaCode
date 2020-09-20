#include <iostream>
#include <algorithm>
#include <string>

#define maxN 100001

typedef long maxn;
typedef std::string str;

str x, y;
maxn res;


void Prepare() {
	std::cin >> x >> y;
}


void Process() {
	maxn i = 1;
	res = 0;
	while (i <= y.size() && y[y.size() - i] == '0') ++i;
	while (i <= x.size() && x[x.size() - i] == '0') ++i, ++res;

	std::cout << res << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	while (q--) {
		Prepare();
		Process();
	}
}