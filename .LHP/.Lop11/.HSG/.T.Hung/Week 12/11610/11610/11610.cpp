#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 78500
#define N pr.size()
#define maxA 1000002
#define A 1000000

typedef long long maxn, maxa;

maxa idx_sp[maxN], idx_ps[maxN], sum[maxN];
bool p[maxA];
std::vector <maxa> pr, rev, cnt;


void Era() {
	p[0] = p[1] = 1;
	for (maxa i = 2; i < A; i++) {
		if (p[i]) continue;
		for (maxa j = i * i; j < A; j += i) p[j] = 1;
		pr.push_back(i);
	}
}


maxa Reverse(maxa p) {
	maxa re = 0;
	while (p) re = re * 10 + (p % 10), p /= 10;
	while (re * 10 < 10000000) re *= 10;
	return re;
}


maxa Count(maxa x) {
	maxa cnt = 0;
	for (maxa i = 0; i < N && pr[i] * pr[i] <= x && x != 1; i++) {
		while (x % pr[i] == 0) x /= pr[i], ++cnt;
	}
	return x != 1 ? cnt + 1 : cnt;
}


void Update(maxa bit[], maxn i, const maxa val) {
	while (i <= N) bit[i] += val, i += (i & (-i));
}

maxa Sum(maxa bit[], maxn i) {
	maxa re = 0;
	while (i) re += bit[i], i -= (i & (-i));
	return re;
}


void Prepare() {
	Era();
	for (maxa i = 0; i < N; i++) rev.push_back(Reverse(pr[i]));
	std::sort(rev.begin(), rev.end());
	for (maxa i = 0; i < N; i++) cnt.push_back(Count(rev[i]));

	for (maxn i = 0; i < N; i++) Update(sum, i + 1, cnt[i]);
}


void Query(const maxn i) {
	std::cout << i + Sum(idx_sp, i + 1) << ' ' << Sum(sum, i + Sum(idx_sp, i + 1) + 1) << '\n';
}


void Delete(const maxa x) {
	maxn i = std::lower_bound(rev.begin(), rev.end(), x) - rev.begin();
	std::cout << i << ' ';
	Update(idx_ps, i + 2, -1);
	Update(sum, i + 1, -cnt[i]);
	i += Sum(idx_ps, i + 1);
	std::cout << i << '\n';
	Update(idx_sp, i + 1, 1);
}


void Process() {
	char opt;
	while (std::cin >> opt) {
		maxa x; std::cin >> x;
		if (opt == 'q') Query(x);
		else Delete(x);
	}
}


int main() {
	Prepare();
	Process();
}