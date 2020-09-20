#include <iostream>
#include <algorithm>
#include <string>

#define maxN 100001

typedef long maxn;
typedef std::string str;

str s;
maxn n, le[maxN], ri[maxN], res[maxN];


void Prepare() {
	std::cin >> s;
	n = s.size();

	ri[0] = 0;
	for (maxn i = 1; i < n; i++) ri[i] = std::max(ri[i - 1], i * (s[i] == 'R'));

	le[n - 1] = n - 1;
	for (maxn i = n - 2; i >= 0; i--) le[i] = std::min(le[i + 1], i + n * (s[i] != 'L'));
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		if (s[i] == 'R') ++res[le[i] - ((le[i] - i) & 1)];
		else ++res[ri[i] + ((i - ri[i]) & 1)];
		--res[i];
	}

	for (maxn i = 0; i < n; i++) std::cout << res[i] + 1 << ' ';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}