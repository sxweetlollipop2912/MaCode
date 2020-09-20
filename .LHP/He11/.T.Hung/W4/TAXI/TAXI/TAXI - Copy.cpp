#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 502
#define X first
#define Y second
#define time(cx, cy) (abs(cx.X - cy.X) + abs(cx.Y - cy.Y))

typedef int maxn, maxa;
typedef std::pair <maxa, maxa> co_t;

maxn n, Cnt[maxN], L[maxN], res;
bool d[maxN][maxN], done[maxN];


maxa Str2Time(std::string& s) {
	return (s[0] * 10 + s[1]) * 60 + (s[3] * 10 + s[4]);
}


void Init() {
	for (maxn i = 0; i < maxN; i++) std::fill(d[i], d[i] + maxN, 0);
	std::fill(done, done + maxN, 0);
}


void Prepare() {
	co_t cst[maxN], cen[maxN];
	maxa st[maxN], en[maxN];

	std::cin >> n;

	for (maxn i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s >> cst[i].X >> cst[i].Y >> cen[i].X >> cen[i].Y;
		st[i] = Str2Time(s);
		en[i] = st[i] + time(cst[i], cen[i]);
	}

	for (maxn i = 1; i <= n; i++) for (maxn j = 1; j <= n; j++) {
		if (en[i] + time(cen[i], cst[j]) + 1 <= st[j])
			d[i][j] = 1;
	}
}


void Process() {
	Cnt[0] = 1, L[0] = 0;

	for (maxn i = 1; i <= n; i++) {
		done[0] = 0, d[0][i] = 1;
		Cnt[i] = L[i] = 0;
		for (maxn j = 0; j < i; j++)
			if (!done[j] && d[j][i]) L[i] = std::max(L[i], L[j] + 1);
		for (maxn j = 0; j < i; j++)
			if (!done[j] && d[j][i] && L[j] == L[i] - 1) Cnt[i] += Cnt[j], done[j] = 1;
	}

	res = 0;
	for (maxn i = 1; i <= n; i++)
		if (!done[i]) res += Cnt[i];

	std::cout << res << '\n';
}


int main() {
	//freopen("taxi.inp", "r", stdin);
	//freopen("taxi.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Init();
		Prepare();
		Process();
	}
}