// PE UVa
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>

//#pragma warning (disable:4996)

#define maxC 32
#define maxN 10000002
#define maxA 16777217

typedef int maxc;
typedef long maxn, maxa;
typedef std::string str;

maxc C;
maxn occur[maxA], bitC[maxC], bitN[maxN], T = 0;
std::vector <maxn> csize;


void Prepare() {
	std::cin >> C;
	for (maxc i = 0; i < C; i++) {
		maxn c; std::cin >> c;
		csize.push_back(c);
	}
	std::sort(csize.begin(), csize.end(), std::greater <maxn>() );
}


void Update(maxn bit[], maxn i, maxn lim, maxn val) {
	while (i <= lim) 
		bit[i] += val, i += i & (-i);
}

maxn Sum(maxn bit[], maxn i) {
	maxn sum = 0;
	while (i > 0)
		sum += bit[i], i -= i & (-i);
	return sum;
}


maxn getTime(const maxn T) {
	return T + Sum(bitN, T);
}


maxc BS(const maxn size) {
	if (csize.empty()) return C;

	maxc l = 0, r = C - 1;
	while (l != r) {
		maxc m = (l + r) / 2;
		if (csize[m] > size) l = m + 1;
		else r = m;
	}

	return csize[l] <= size ? l : C;
}


void Access(const maxa data) {
	if (!occur[data]) Update(bitC, 1, C, 1);
	else {
		Update(bitC, BS(getTime(T) - getTime(occur[data])) + 1, C, 1);
		Update(bitN, occur[data] + 1, maxN - 1, -1);
	}
	occur[data] = ++T;
}


maxn Miss(const maxn cache_id) {
	return Sum(bitC, cache_id);
}


void Process() {
	str s;
	while (std::cin >> s && s != "END") {
		if (s == "ADDR") {
			maxa x; 
			std::cin >> x;
			Access(x);
		}
		if (s == "RANGE") {
			maxa b, y, n; 
			std::cin >> b >> y >> n;
			for (maxa i = 0; i < n; i++) Access(b + y * i);
		}
		if (s == "STAT") {
			for (maxc c = 0; c < C; c++) std::cout << Miss(C - c) << ' ';
			std::fill(bitC, bitC + maxC, 0);
			std::cout << '\n';
		}
	}
}


int main() {
	//freopen("11423.inp", "r", stdin);
	//freopen("11423.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}