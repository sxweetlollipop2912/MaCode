#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#pragma warning(disable:4996)

#define maxN 101
#define maxA 30002
#define st pos[0]
#define en pos[1]

typedef int maxn, maxa;

maxn n, cnt[maxA];
std::vector <maxa> dis, pos;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n * (n - 1) / 2; i++) {
		maxa x; std::cin >> x;
		++cnt[x];
		dis.push_back(x);
	}
	std::sort(dis.begin(), dis.end());
}


bool change(const maxa x, const maxn val) {
	bool re = 1;
	for (maxn i = 0; i < pos.size(); i++)
		if ((cnt[abs(x - pos[i])] += val) < 0) re = 0;
	return re;
}


bool Try(maxn back) {
	while (back >= 0 && !cnt[dis[back]]) --back;

	if (back < 0) return 1;

	if (change(st + dis[back], -1)) {
		pos.push_back(st + dis[back]);
		if (Try(back - 1)) return 1;
		pos.pop_back();
	}
	change(st + dis[back], 1);

	if (change(en - dis[back], -1)) {
		pos.push_back(en - dis[back]);
		if (Try(back - 1)) return 1;
		pos.pop_back();
	}
	change(en - dis[back], 1);

	return 0;
}


bool Process() {
	pos.push_back(0); pos.push_back(dis.back()); --cnt[dis.back()];
	Try(dis.size() - 2);

	if (pos.size() != n) return 0;

	std::sort(pos.begin(), pos.end());
	for (maxn i = 0; i < n; i++) std::cout << pos[i] << ' ';
	return 1;
}


int main() {
	//freopen("ppoint.inp", "r", stdin);
	//freopen("ppoint.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << -1;
}