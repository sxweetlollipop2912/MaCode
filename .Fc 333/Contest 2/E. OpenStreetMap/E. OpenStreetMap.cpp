#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 3001
#define maxA 1000000001
#define next(a) (maxa)(((maxa)(a)*x + y) % z)

typedef int maxn;
typedef long long maxa;

maxn m, n, A, B;
maxa a[maxN][maxN], mn[maxN][maxN], g0, x, y, z, res;


void Prepare() {
	std::cin >> m >> n >> A >> B >> g0 >> x >> y >> z;

	maxa prev = a[0][0] = g0;
	for (maxn j = 1; j < n; j++) a[0][j] = prev = next(prev);

	for (maxn i = 1; i < m; i++) 
		for (maxn j = 0; j < n; j++) 
			a[i][j] = prev = next(prev);
}


void MinDeque1(const maxn row) {
	maxn d = B;
	std::vector <maxn> de;

	for (maxn j = 0; j < n; j++) {
		while (!de.empty() && a[row][de.back()] >= a[row][j]) {
			maxn pos = de.back();
			de.pop_back();
			maxn l = de.empty() ? 0 : de.back() + 1, r = j;

			if (r - l + 1 < d) continue;
			for (maxn jj = std::max(pos - d + 1, l); jj <= std::min(pos, r - d + 1); jj++) mn[row][jj] = a[row][pos];
		}
		de.push_back(j);
	}

	while (!de.empty()) {
		maxn pos = de.back();
		de.pop_back();
		maxn l = de.empty() ? 0 : de.back() + 1, r = n - 1;
		
		if (r - l + 1 < d) continue;
		for (maxn jj = std::max(pos - d + 1, l); jj <= std::min(pos, r - d + 1); jj++) mn[row][jj] = a[row][pos];
	}
}


void Process1() {
	for (maxn i = 0; i < m; i++) 
		MinDeque1(i);
}


maxa MinDeque2(const maxn col) {
	maxn d = A;
	std::vector <maxn> de;
	std::vector <maxa> mn2(m - d + 1);

	for (maxn i = 0; i < m; i++) {
		while (!de.empty() && mn[de.back()][col] >= mn[i][col]) {
			maxn pos = de.back();
			de.pop_back();
			maxn l = de.empty() ? 0 : de.back() + 1, r = i;

			if (r - l + 1 < d) continue;
			for (maxn ii = std::max(pos - d + 1, l); ii <= std::min(pos, r - d + 1); ii++) mn2[ii] = mn[pos][col];
		}
		de.push_back(i);
	}

	while (!de.empty()) {
		maxn pos = de.back();
		de.pop_back();
		maxn l = de.empty() ? 0 : de.back() + 1, r = m - 1;

		if (r - l + 1 < d) continue;
		for (maxn ii = std::max(pos - d + 1, l); ii <= std::min(pos, r - d + 1); ii++) mn2[ii] = mn[pos][col];
	}

	maxa re = 0;
	for (maxn i = 0; i < mn2.size(); i++) re += mn2[i];
	return re;
}


void Process2() {
	res = 0;
	for (maxn i = 0; i <= n - B; i++) res += MinDeque2(i);
	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process1();
	Process2();
}