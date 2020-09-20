#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

#define maxA 900002
#define A 900000
#define maxN 1002
#define N 1000
#define PR pr.size()

typedef long long maxa;

maxa L, R, s[maxA], CNT;
bool p[maxN], done[maxA];
std::vector <maxa> pr;


void Prepare() {
	std::cin >> L >> R;
}


void Era() {
	p[0] = p[1] = 1;
	for (maxa i = 2; i <= N; i++) {
		if (p[i]) continue;
		for (maxa j = i * i; j <= N; j += i) p[j] = 1;
		pr.push_back(i);
	}
}


maxa Sum(maxa x) {
	maxa re = 0, LIM = x;
	for (maxa i = 0; i < PR && pr[i] * pr[i] <= LIM && x != 1; i++) {
		maxa m = 0, cnt = 1;
		while (x % pr[i] == 0) x /= pr[i], cnt *= pr[i], m += cnt;
		re += re * m + m;
	}
	if (x != 1) re += re * x + x;
	return re + 1 - LIM;
}


void Process() {
	Era();
	for (maxa i = L; i <= R; i++) {
		if (done[i]) continue;
		maxa si = Sum(i); done[i] = 1;
		if (si > R) continue;
		done[si] = 1;
		if (si > i && Sum(si) == i) std::cout << i << ' ' << si << '\n';
	}
}


int main() {
	//freopen("ami.inp", "r", stdin);
	//freopen("ami.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}