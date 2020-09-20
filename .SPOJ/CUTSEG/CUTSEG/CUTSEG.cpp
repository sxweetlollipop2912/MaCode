#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 202
//#define maxC 10
#define val(x) ((x)*(x))
#define length first
#define color second
#define le first
#define ri second

typedef char maxc;
typedef unsigned long long maxn;
typedef std::pair <maxn, maxc> segt;
typedef std::pair <maxn, maxn> leftt;

maxn n;
std::vector <segt> seg(1);
maxn f[maxN][maxN];
leftt l[maxN][maxN];


void Prepare() {
	std::cin >> n >> seg.back().color;
	seg.back().length = 1;

	for (maxn i = 1; i < n; i++) {
		maxc col;
		std::cin >> col;

		if (col == seg.back().color) ++seg.back().length;
		else seg.push_back(segt(1, col));
	}

	n = seg.size();
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		f[i][i] = val(seg[i].length);
		l[i][i].le = l[i][i].ri = seg[i].length;
	}

	for (maxn len = 2; len <= n; len++) {
		for (maxn L = 0; L <= n - len; L++) {
			maxn R = L + len - 1;
			f[L][R] = 0;
			for (maxn M = L; M < R; M++) {
				// f[L][M] & f[M + 1][R]
				if (f[L][M] + f[M + 1][R] > f[L][R]) {
					f[L][R] = f[L][M] + f[M + 1][R];
					l[L][R].le = l[L][M].le;
					l[L][R].ri = l[M + 1][R].ri;
				}

				maxn nVal = f[L][M] - val(l[L][M].le) + f[M + 1][R] - val(l[M + 1][R].ri) + val(l[L][M].le + l[M + 1][R].ri);
				if (seg[L].color == seg[R].color && nVal > f[L][R]) {
					f[L][R] = nVal;
					l[L][R].le = l[L][R].ri = l[L][M].le + l[M + 1][R].ri;
				}

				nVal = f[L][M] - val(l[L][M].ri) + f[M + 1][R] - val(l[M + 1][R].ri) + val(l[L][M].ri + l[M + 1][R].ri);
				if (seg[M].color == seg[R].color && nVal > f[L][R]) {
					f[L][R] = nVal;
					l[L][R].ri = l[L][M].ri + l[M + 1][R].ri;
					l[L][R].le = l[L][M].le;
				}

				nVal = f[L][M] - val(l[L][M].le) + f[M + 1][R] - val(l[M + 1][R].le) + val(l[L][M].le + l[M + 1][R].le);
				if (seg[L].color == seg[M + 1].color && nVal > f[L][R]) {
					f[L][R] = nVal;
					l[L][R].le = l[L][M].le + l[M + 1][R].le;
					l[L][R].ri = l[M + 1][R].ri;
				}
			}
		}
	}

	std::cout << f[0][n - 1];
}


int main() {
	std::ios_base::sync_with_stdio(0);

	Prepare();
	Process();
}