// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

#pragma warning(disable:4996)

#define maxA 1000002
#define A 999999

typedef long maxa;

maxa n, lp[maxA], cnt[maxA], Sum[maxA], Idx[maxA];
std::vector <maxa> pr, V;
std::map <maxa, maxa> map;


maxa reverse(maxa x) {
	maxa re = 0;
	for (; x != 0; x /= 10) re = re * 10 + (x % 10);
	return re;
}


void Prepare() {
	for (maxa i = 2; i <= A; i++) {
		if (!lp[i]) {
			lp[i] = i, cnt[i] = 1;
			pr.push_back(i);
		}
		for (maxa j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i <= A; j++)
			lp[pr[j] * i] = pr[j],
			cnt[pr[j] * i] = cnt[i] + 1;
	}

	for (maxa i = 2; i <= A; i++) {
		maxa ri = reverse(i);
		while (ri < 100000) ri *= 10;

		if (lp[i] != i) continue;
		V.push_back(ri);
	}

	std::sort(V.begin(), V.end());
	for (maxa i = 0; i < V.size(); i++) map[V[i]] = i;

	n = V.size();
}


void Update(maxa bit[], const maxa n, maxa i, const maxa x) {
	for (; i <= n; i += (i & (-i)))
		bit[i] += x;
}

maxa GetSum(maxa bit[], const maxa n, maxa i) {
	maxa re = 0;
	for (; i > 0; i -= (i & (-i)))
		re += bit[i];
	return re;
}


void Delete(const maxa x) {
	maxa idx = map[x];
	Update(Idx, n, idx + 2, -1);
	Update(Sum, n, idx + 1, -cnt[x] - 2);
}


maxa Query(const maxa idx) {
	maxa l = 0, r = n - 1;
	while (l != r) {
		maxa m = (l + r + 1) / 2;
		if (m + GetSum(Idx, n, m + 1) > idx) r = m - 1;
		else l = m;
	}
	return GetSum(Sum, n, l + 1);
}


void Process() {
	for (maxa i = 0; i < V.size(); i++)
		Update(Sum, n, i + 1, cnt[V[i]] + 2);

	char c; maxa x;
	while (std::cin >> c >> x) {
		if (c == 'q') {
			std::cout << Query(x) << '\n';
		}
		else Delete(x / 10);
	}
}


int main() {
	freopen("11610.inp", "r", stdin);
	freopen("11610.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}