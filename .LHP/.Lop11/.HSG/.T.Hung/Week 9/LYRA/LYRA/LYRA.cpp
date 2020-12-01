#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxS 100003
#define le 0
#define ri 1
#define a 0
#define b 1

typedef long maxn;
typedef std::string str;

str s[2];
maxn step[2][maxS], f[2], res;
bool pos[2][maxS];


void Prepare() {
	std::cin >> s[a] >> s[b];
}


void Process() {
	for (int p = 0; p <= 1; p++) for (maxn i = 0; i < s[p].size(); i++) {
		if      (s[p][i] == '1') ++f[p], pos[p][f[p]] = le, step[p][f[p]] = 0;
		else if (s[p][i] == '2') ++f[p], pos[p][f[p]] = ri, step[p][f[p]] = 0;
		else if (s[p][i] == 'L') --step[p][f[p]];
		else if (s[p][i] == 'R') ++step[p][f[p]];

		else {
			maxn x = step[p][f[p]] < 0 ? (step[p][f[p]] - (pos[p][f[p]] == le)) / 2 : (step[p][f[p]] + (pos[p][f[p]] == ri)) / 2;
			step[p][--f[p]] += x;
		}
	}

	for (int p = 0; p <= 1; p++) for (maxn fl = f[p]; fl > 0; fl--) {
		maxn x = step[p][fl] < 0 ? (step[p][fl] - (pos[p][fl] == le)) / 2 : (step[p][fl] + (pos[p][fl] == ri)) / 2;
		step[p][fl - 1] += x;
		pos[p][fl] ^= ((step[p][fl]) & 1), step[p][fl] = 0;
	}

	res = f[a] + f[b]; int side_a = 0;
	for (maxn fl = 0, d = 0; fl <= f[a] && fl <= f[b]; fl++) {
		if (pos[a][fl] == pos[b][fl]) d *= 2;
		else {
			if (!d) side_a = pos[a][fl];
			if (pos[a][fl] == side_a) d = d * 2 + 1;
			else d = d * 2 - 1;
		}
		res = std::min(res, f[a] - fl + f[b] - fl + d);
	}

	std::cout << res;
}


int main() {
	//freopen("lyra.inp", "r", stdin);
	//freopen("lyra.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}