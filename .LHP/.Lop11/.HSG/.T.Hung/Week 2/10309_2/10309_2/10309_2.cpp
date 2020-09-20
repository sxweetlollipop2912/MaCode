// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 12
#define maxM 101
#define n 10
#define maxB (1 << 10)
#define off '#'
#define on 'O'
#define rev(b, i) ((b) ^ (1 << (i)))
#define isOn(b, i) (((b) >> (i)) & 1)

typedef int maxn, maxb;
typedef std::string str;

maxn res;
maxb a[maxN];


void Prepare() {
	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) {
		char c; std::cin >> c;
		if ((c == on && !isOn(a[i], j)) || (c == off && isOn(a[i], j))) a[i] = rev(a[i], j);
	}
}


maxn Execute(maxb& cur, maxb& below, maxb move) {
	maxn cnt = 0;
	for (maxn i = 0; i < n; i++) {
		if (!isOn(move, i)) continue;
		below = rev(below, i), cur = rev(cur, i);
		if (i > 0) cur = rev(cur, i - 1);
		if (i < n - 1) cur = rev(cur, i + 1);
		++cnt;
	}
	return cnt;
}


maxn Try(maxb move) {
	maxn cnt = 0;
	maxb tmp[2]; bool p = 0;
	tmp[!p] = a[0];

	for (maxn i = 0; i < n; i++) {
		p = !p, tmp[!p] = a[i + 1];
		cnt += Execute(tmp[p], tmp[!p], move);
		move = tmp[p];
	}

	return !tmp[p] ? cnt : maxM;
}


void Process() {
	res = maxM;
	for (maxb move = 0; move < maxB; move++) res = std::min(res, Try(move));

	if (res != maxM) std::cout << res << '\n';
	else std::cout << "-1\n";
}


int main() {
	//freopen("10309.inp", "r", stdin);
	//freopen("10309.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	str name;
	while (std::cin >> name && name != "end") {
		std::cout << name << ' ';
		Prepare();
		Process();
	}
}