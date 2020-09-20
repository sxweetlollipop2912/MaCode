#include <iostream>
#include <algorithm>

#define maxN 200002
#define root first
#define rank second
#define unite 1
#define move 2
#define retu 3

typedef long maxn;
typedef std::pair <maxn, maxn> info;

maxn n, CNT;
maxn name[maxN], size[maxN], sum[maxN];
info set[maxN];


void InitSet(const maxn x, const maxn s) {
	size[x] = 1, sum[x] = s, set[x].root = x, set[x].rank = 0;
}


void Prepare() {
	//std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		name[i] = i;
		InitSet(i, i + 1);
	}
	CNT = n;
}


maxn Root(maxn sx) {
	while (set[sx].root != sx) sx = set[sx].root;
	return sx;
}

void Union(maxn sx, maxn sy) {
	sx = Root(sx);
	sy = Root(sy);

	if (sx == sy) return;

	if (set[sx].rank < set[sy].rank) {
		set[sx].root = sy;
		sum[sy] += sum[sx], size[sy] += size[sx];
	}
	else {
		set[sy].root = sx;
		sum[sx] += sum[sy], size[sx] += size[sy];
		if (set[sx].rank == set[sy].rank) ++set[sx].rank;
	}
}


void Seperate(const maxn x) {
	maxn i = name[x];
	if (i != set[i].root) sum[i] -= (x + 1), --size[i];
	do {
		i = set[i].root;
		sum[i] -= (x + 1), --size[i];
	} while (i != set[i].root);

	name[x] = ++CNT;
	InitSet(CNT, x + 1);
}


void Process() {
	maxn m = 0;
	std::cin >> m;

	while (m--) {
		int opt;
		maxn x;
		std::cin >> opt >> x, --x;

		if (opt != retu) {
			maxn y;
			std::cin >> y, --y;

			if (opt == move) Seperate(x);
			Union(name[x], name[y]);
		}
		else {
			x = Root(name[x]);
			std::cout << size[x] << ' ' << sum[x] << '\n';
		}
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n) {
		Prepare();
		Process();
	}
}