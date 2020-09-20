#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <math.h>

#define maxN 6
#define S 7
#define H 0
#define J 1
#define n 5
#define row(x) ((x) / n + 1)
#define col(x) ((x) % n)
#define num(i, j) ((i) * n + (j))
#define on(b, i) ((b) | (1 << (i)))
#define isOn(b, i) (((b) >> i) & 1)

typedef int maxn, maxr;
typedef long maxb;

bool map[maxN][maxN];
maxn res, CNT;
std::queue <maxn> bfs;


void Prepare() {
	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) {
		char c;
		std::cin >> c;
		map[i][j] = c == 'H' ? H : J;
	}
}


bool Check(maxb b) {
	maxn cnt[2] = {}; bool done[n * n] = {};

	/*for (maxn i = 0; i < n * n; i++) {
		if (!isOn(b, i)) continue;
		bfs.push(i); done[i] = 1; break;
	}*/
	maxn i = log2(b & (-b));
	done[i] = 1;
	bfs.push(i);

	while (!bfs.empty()) {
		maxn cur = bfs.front(); bfs.pop();
		++cnt[map[row(cur)][col(cur)]];

		if (cur - n >= 0 && isOn(b, cur - n) && !done[cur - n]) {
			bfs.push(cur - n);
			done[cur - n] = 1;
		}
		if (cur + n < n * n && isOn(b, cur + n) && !done[cur + n]) {
			bfs.push(cur + n);
			done[cur + n] = 1;
		}
		if (col(cur) > 0 && isOn(b, cur - 1) && !done[cur - 1]) {
			bfs.push(cur - 1);
			done[cur - 1] = 1;
		}
		if (col(cur) < n - 1 && isOn(b, cur + 1) && !done[cur + 1]) {
			bfs.push(cur + 1);
			done[cur + 1] = 1;
		}
	}

	return cnt[H] + cnt[J] == S && cnt[J] > cnt[H];
}


void Process() {
	for (int i1 = 0; i1 < n * n; i1++) for (int i2 = i1 + 1; i2 < n * n; i2++) for (int i3 = i2 + 1; i3 < n * n; i3++) for (int i4 = i3 + 1; i4 < n * n; i4++)
		for (int i5 = i4 + 1; i5 < n * n; i5++) for (int i6 = i5 + 1; i6 < n * n; i6++) for (int i7 = i6 + 1; i7 < n * n; i7++) {
			maxb b = 0; 
			b = on(b, i1), b = on(b, i2), b = on(b, i3), b = on(b, i4), b = on(b, i5), b = on(b, i6), b = on(b, i7);
			//++CNT; 
			res += Check(b);
		}
	std::cout << res;
}


int main() {
	//freopen("cowrig.inp", "r", stdin);
	//freopen("cowrig.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}