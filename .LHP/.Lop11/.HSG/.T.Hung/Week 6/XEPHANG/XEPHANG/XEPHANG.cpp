#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

#define maxA 1000000003
#define maxN 250005
#define N a.size()
#define st 0
#define en 1000000001
#define prev first
#define next second
#define P 0
#define L 1

typedef long maxa;
typedef std::pair <maxa, maxa> p_t;

maxa n, res[maxN], Q, q[maxN], idQ[maxN], pos[maxN];
bool opt[maxN];
std::vector <maxa> a;
std::map <maxa, maxa> map;
p_t link[maxN];
std::vector <p_t> move;


void Push(const maxa x) {
	map[x] = N, link[N].prev = N - 1, link[N].next = N + 1;
	a.push_back(x);
}


bool cmp(const maxa x, const maxa y) {
	return q[x] < q[y];
}


void Prepare() {
	std::cin >> n;

	Push(st); link[0].prev = -1;

	for (maxa i = 1; i <= n; i++) {
		maxa x, y; std::cin >> x >> y;

		if (map.find(x) == map.end()) Push(x);
		if (map.find(y) == map.end()) Push(y);
		if (map.find(x + 1) == map.end()) Push(x + 1);

		move.push_back(p_t(x, y));
	}

	Push(en); link[N - 1].next = -1;
	std::sort(a.begin(), a.end());

	std::cin >> Q;
	for (maxa i = 0; i < Q; i++) {
		char c; std::cin >> c >> q[i];
		opt[i] = c == 'L', idQ[i] = i;
	}
	std::sort(idQ, idQ + Q, cmp);
}


void Move(const maxa x, const maxa y) { // move x to y
	maxa idx = map[x], idy = map[y];

	link[link[idx].next].prev = link[idx].prev;
	link[link[idx].prev].next = link[idx].next;

	link[idx].prev = idy, link[idx].next = link[idy].next;
	link[link[idx].prev].next = idx;
	link[link[idx].next].prev = idx;
}


void Process() {
	for (maxa i = 0; i < move.size(); i++) Move(move[i].first, move[i].second);
	for(maxa i = 0, pos = 0; i != -1; i = link[i].next, pos++) pos[a[i]] = 

	for (maxa i = 0; i < Q; i++) {

	}
}