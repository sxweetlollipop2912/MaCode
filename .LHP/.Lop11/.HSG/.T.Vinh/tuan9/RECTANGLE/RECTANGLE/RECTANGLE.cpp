#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 25001
#define maxA 1000002
#define pos first
#define idx second

typedef int maxn;
typedef long maxa;
typedef std::pair <maxa, maxn> v_t;

maxn n, res;
maxa xa[maxN], ya[maxN], xb[maxN], yb[maxN], mxX, mxY;
std::vector <v_t> vx[maxA], vy[maxA];
std::vector <maxa> mxx[maxA], mxy[maxA];


void Prepare() {
	std::cin >> n;
	
	for (maxn i = 0; i < n; i++) {
		std::cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];

		vx[xa[i]].push_back(v_t(ya[i], i)); vx[xb[i]].push_back(v_t(ya[i], i));
		vy[ya[i]].push_back(v_t(xa[i], i)); vy[yb[i]].push_back(v_t(xa[i], i));

		mxX = std::max(mxX, xb[i]), mxY = std::max(mxY, yb[i]);
	}

	for (maxn x = 0; x <= mxX; x++) {
		std::sort(vx[x].begin(), vx[x].end());
		if (vx[x].empty()) continue;
		
		mxx[x].push_back(yb[vx[x][0].idx]);
		for (maxn i = 1; i < vx[x].size(); i++) mxx[x].push_back(std::max(mxx[x].back(), yb[vx[x][i].idx]));
	}
	
	for (maxn y = 0; y <= mxY; y++) {
		std::sort(vy[y].begin(), vy[y].end());
		if (vy[y].empty()) continue;

		mxy[y].push_back(xb[vy[y][0].idx]);
		for (maxn i = 1; i < vy[y].size(); i++) mxy[y].push_back(std::max(mxy[y].back(), xb[vy[y][i].idx]));
	}
}


maxn upper(const std::vector <v_t>& v, const maxa val) {
	maxn l = 0, r = v.size() - 1;
	while (l != r) {
		maxn m = (l + r) / 2;
		if (v[m].pos <= val) l = m + 1;
		else r = m;
	}
	return v[l].pos > val ? l : v.size();
}

maxn lower(const std::vector <v_t>& v, const maxa val) {
	maxn l = 0, r = v.size() - 1;
	while (l != r) {
		maxn m = (l + r) / 2;
		if (v[m].pos < val) l = m + 1;
		else r = m;
	}
	return v[l].pos >= val ? l : v.size();
}


void Process() {
	res = n;

	for (maxn i = 0; i < n; i++) {
		bool exp = 1; maxn it = 0;

		it = lower(vx[xa[i]], ya[i]);
		if (it && mxx[xa[i]][it - 1] >= ya[i]) exp = 0;
		else if (upper(vx[xa[i]], yb[i]) - lower(vx[xa[i]], ya[i]) > 1) exp = 0;

		it = lower(vx[xb[i]], ya[i]);
		if (it && mxx[xb[i]][it - 1] >= ya[i]) exp = 0;
		else if (upper(vx[xb[i]], yb[i]) - lower(vx[xb[i]], ya[i]) > 1) exp = 0;

		it = lower(vy[ya[i]], xa[i]);
		if (it && mxy[ya[i]][it - 1] >= xa[i]) exp = 0;
		else if (upper(vy[ya[i]], xb[i]) - lower(vy[ya[i]], xa[i]) > 1) exp = 0;

		it = lower(vy[yb[i]], xa[i]);
		if (it && mxy[yb[i]][it - 1] >= xa[i]) exp = 0;
		else if (upper(vy[yb[i]], xb[i]) - lower(vy[yb[i]], xa[i]) > 1) exp = 0;

		res -= !exp;
	}

	std::cout << res;
}


int main() {
	//freopen("rectangle.inp", "r", stdin);
	//freopen("rectangle.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}