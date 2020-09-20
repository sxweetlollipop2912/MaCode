#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 300001
#define maxM 300001

typedef long maxn, maxa;

maxn n;
maxa M;
std::vector <maxa> a;


void Prepare() {
	std::cin >> n >> M;
	a.resize(n + 1);
	a[0] = 0;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i];
}


bool Check(const maxa lim, std::vector <maxa> a) {
	for (maxn i = 1; i <= n; i++) {
		maxa step = a[i - 1] >= a[i] ? a[i - 1] - a[i] : a[i - 1] - a[i] + M;
		if (step <= lim) a[i] = a[i - 1];
		else if (a[i - 1] > a[i]) return 0;
	}
	return 1;
}


void Process() {
	maxa l = 0, r = M;

	while (l != r) {
		maxa m = (l + r) / 2;
		if (Check(m, a)) r = m;
		else l = m + 1;
	}

	std::cout << l;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}