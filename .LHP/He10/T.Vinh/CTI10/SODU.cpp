#include <iostream>
#include <cstdio>
#include <queue>

#define maxN 1000000001
#define maxA 1000001
#define maxB 1000001
#define maxP 1000001
#define maxR 1000000

typedef long maxa;

maxa N, P, A, B, R, res;
bool ex[maxP];
std::queue <maxa> bfs;


void Prepare() {
	std::cin >> N >> P >> A >> B >> R;
}


bool Push(const maxa &x) {
	maxa tmp = (x + A) % P;
	if (tmp == R) return 1;
	if (!ex[tmp]) {
		ex[tmp] = 1;
		bfs.push(tmp);
	}

	tmp = (x + A) % P;
	if (tmp == R) return 1;
	if (!ex[tmp]) {
		ex[tmp] = 1;
		bfs.push(tmp);
	}

	return 0;
}


maxa BFS() {
	Push(N);
	if (N < maxP) ex[N] = 1;
	maxa time = 1;

	while (!bfs.empty()) {
		time++;
		maxa cnt = bfs.size();

		while (cnt--) {
			if (Push(bfs.front())) return time;
			bfs.pop();
		}
	}

	return -1;
}


void Process() {
	res = BFS();
	std::cout << res;
}


int main() {
	freopen("sodu.inp", "r", stdin);
	freopen("sodu.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}