#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>

#define maxN 102
#define maxK 1000000000001

typedef int maxn;
typedef long long maxk;
typedef std::string str;

maxn n, LEN;
maxk k, len[maxN], f[maxN], done[27], res;
str s;


void Prepare() {
	std::cin >> n >> k >> s;
	s = "0" + s;
}


void Update() {
	for (maxn i = n; i >= LEN; i--) {
		f[i] = f[i - 1];
	}
	done[s[LEN] - 'a'] = f[LEN];
	for (maxn i = LEN + 1; i <= n; i++) {
		f[i] -= done[s[i] - 'a'];
		done[s[i] - 'a'] = f[i] + done[s[i] - 'a'];
		f[i] += f[i - 1];
	}
	len[LEN] = f[n];
}


void Process() {
	std::fill(f, f + maxN, 1);
	len[0] = 1;
	for (LEN = 1; LEN <= n; LEN++) {
		std::fill(done, done + 27, 0);
		Update();
	}
	for (LEN = n; LEN >= 0 && k; LEN--) {
		maxk take = std::min(len[LEN], k);
		res += (n - LEN)*take;
		k -= take;
	}
	if (k) std::cout << "-1";
	else std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}