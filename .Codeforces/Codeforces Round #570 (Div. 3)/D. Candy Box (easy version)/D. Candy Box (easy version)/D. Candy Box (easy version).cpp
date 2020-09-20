#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

#define maxN 200002

typedef long maxn;

maxn n, a[maxN], cnt[maxN], res;
std::vector <maxn> len;


void Init() {
	memset(cnt, maxN, 0);
	len.clear();
	res = 0;
}


void Process() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i];
		++cnt[a[i]];
	}
	for (maxn i = 0; i < n; i++) {
		if (!cnt[a[i]]) continue;
		len.push_back(cnt[a[i]]);
		cnt[a[i]] = 0;
	}
	std::sort(len.begin(), len.end());
	
	maxn mn = len.back() + 1;
	for (maxn i = len.size() - 1; i >= 0; i--) {
		mn = std::min(mn - 1, len[i]);
		if (mn > 0) res += mn;
		//std::cout << a[i] << ' ' << len[i] << '\n';
	}
	std::cout << res << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long q;
	std::cin >> q;

	while (q--) {
		Init();
		Process();
	}
}