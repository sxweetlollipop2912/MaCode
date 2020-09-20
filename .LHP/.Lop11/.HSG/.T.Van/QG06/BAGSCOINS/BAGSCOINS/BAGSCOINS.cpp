#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 70002
#define maxA 70002

typedef long maxn, maxa;

maxn n, last[maxA], id[maxN], con[maxN];
maxa S, a[maxN];
bool take[maxN];
std::vector <maxa> st;


bool cmp(const maxn x, const maxn y) {
	return a[x] < a[y];
}


void Prepare() {
	std::cin >> n >> S;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i], id[i] = i;
	std::sort(id, id + n + 1, cmp);
}


bool Process() {
	st.push_back(0); S -= a[id[n]];

	for (maxn ii = 1; ii < n; ii++) for (maxa j = st.size() - 1; j >= 0; j--) {
		maxn i = id[ii];
		if (st[j] + a[i] > S || last[st[j] + a[i]]) continue;
		last[st[j] + a[i]] = ii;
		st.push_back(st[j] + a[i]);
	}

	if (S != 0 && !last[S]) return 0;

	while (S != 0) take[last[S]] = 1, S -= a[id[last[S]]];
	take[n] = 1;

	for (maxn i = 2; i <= n; i++) 
		if (!take[i - 1]) con[id[i]] = id[i - 1];

	for (maxn i = 1; i <= n; i++) {
		std::cout << a[i] - a[con[i]] << ' ';
		if (con[i]) std::cout << "1 " << con[i] << '\n';
		else std::cout << "0\n";
	}

	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << -1;
}