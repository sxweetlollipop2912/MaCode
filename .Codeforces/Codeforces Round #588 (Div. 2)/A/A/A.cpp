#include <iostream>
#include <algorithm>

#define maxN 7002

typedef int maxn;
typedef long long maxa;

maxn n, id[maxN];
maxa a[maxN], s[maxN], res;
bool take[maxN];


bool cmp(const maxn x, const maxn y) {
	return a[x] < a[y];
}

void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i], id[i] = i;
	std::sort(id, id + n, cmp);
	for (maxn i = 0; i < n; i++) std::cin >> s[i];
}


void Process() {
	res = 0;
	for (maxn i = 1; i < n; i++) {
		if (a[id[i]] != a[id[i - 1]]) continue;
		for (maxn j = 0; j <= i; j++) {
			if ((a[id[i]] | a[id[j]]) == a[id[i]]) take[id[j]] = 1;
		}
	}
	for (maxn i = 0; i < n; i++) if (take[i]) res += s[i];
	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}