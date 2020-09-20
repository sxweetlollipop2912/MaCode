#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 12
#define maxB 1024
#define maxR 101
#define n 10
#define on(b, i) ((b) | (1 << ((i))))
#define off(b, i) ((b) & (~(1 << ((i)))))
#define rev(b, i) ((b) ^ (1 << ((i))))
#define isOn(b, i) (((b) >> ((i))) & 1)

typedef int maxn, maxb;

maxb st[maxN], tmp[2];
maxn res;


void Prepare() {
	for (maxn i = 1; i <= n; i++) for (maxn j = 0; j < n; j++) {
		char c; std::cin >> c;
		if (c == 'O') st[i] = on(st[i], j);
		//else st[i] = off(st[i], j);
	}
}


maxn Execute(const maxb todo, const bool i) {
	//std::cout << "exec " << todo << ' ' << tmp[i] << '\n';
	maxn cnt = 0;
	for (maxn j = 0; j < n; j++) {
		if (!isOn(todo, j)) continue;
		//std::cout << st[i] << ' ';
		tmp[i] = rev(tmp[i], j);
		if (j > 0) tmp[i] = rev(tmp[i], j - 1);
		if (j < n - 1) tmp[i] = rev(tmp[i], j + 1);
		//std::cout << st[i] << '\n';
		tmp[!i] = rev(tmp[!i], j);
		++cnt;
	}
	//std::cout << tmp[i] << '\n';
	return cnt;
}


maxn Try(maxb todo) {
	bool p = 1; tmp[p] = todo, tmp[!p] = st[1];
	maxn cnt = 0;
	for (maxn i = 1; i < n; i++) {
		p = !p, todo = tmp[!p];
		tmp[!p] = st[i + 1];
		cnt += Execute(todo, p);
	}
	return !tmp[!p] ? cnt : maxR;
}


void Process() {
	res = maxR;
	//Execute(st[1], 2);
	for (maxb i = 0; i < maxB; i++) {
		res = std::min(res, Try(i));
		if (Try(i) == 46) std::cout << i << '\n';
		if (i == 645) std::cout << "t " << Try(i) << '\n';
	}
	std::cout << Try(645) << '\n';
	if (res != maxR) std::cout << res;
	else std::cout << -1;
}


int main() {
	Prepare();
	Process();
}