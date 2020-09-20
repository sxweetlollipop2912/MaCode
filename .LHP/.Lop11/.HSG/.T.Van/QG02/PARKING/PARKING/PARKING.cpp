#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define maxN 200004
#define maxX 1000001
#define left first
#define right second
#define park 1
#define leave 2
#define dummy1 n + 1
#define dummy2 n + 2
#define dist(l, r) (((l) + (r)) / 2 - (l))

typedef long maxn, maxx;
typedef std::pair <maxn, maxn> p_t;

maxn n, turn, l_most, r_most, location[maxX];
bool done[maxX];
p_t ad[maxX];


void Prepare() {
	std::cin >> n >> turn;
}


class cmp {
public:
	bool operator() (const p_t p1, const p_t p2) {
		return dist(location[p1.left], location[p1.right]) < dist(location[p2.left], location[p2.right])
			|| (dist(location[p1.left], location[p1.right]) == dist(location[p2.left], location[p2.right]) && location[p1.left] > location[p2.left]);
	}
};
std::priority_queue <p_t, std::vector <p_t>, cmp > pq;


bool valid(const p_t p) {
	return done[p.left] && done[p.right] && ad[p.left].right == p.right && ad[p.right].left == p.left;
}


maxn Park(const maxx id) {
	while (!valid(pq.top()) || (location[id] = (location[pq.top().left] + location[pq.top().right]) / 2) < 1 || location[id] > n) pq.pop();

	ad[id].left = pq.top().left, ad[id].right = pq.top().right;
	ad[ad[id].left].right = id;
	ad[ad[id].right].left = id;

	pq.pop();
	pq.push(p_t(ad[id].left, id));
	pq.push(p_t(id, ad[id].right));

	done[id] = 1;
	return location[id];
}


void Leave(const maxx id) {
	done[id] = 0;

	if (location[id] == 1) location[dummy1] = 2 - location[ad[id].right];
	if (location[id] == n) location[dummy2] = 2 * n - location[ad[id].left];

	ad[ad[id].left].right = ad[id].right;
	ad[ad[id].right].left = ad[id].left;

	pq.push(p_t(ad[id].left, ad[id].right));
}


void Process() {
	location[dummy1] = 2 - 2 * n + 1, location[dummy2] = 2 * n - 1;
	ad[dummy1].right = dummy2, ad[dummy2].left = dummy1;

	pq.push(p_t(n + 1, n + 2)); done[dummy1] = done[dummy2] = 1;

	while (turn--) {
		int opt; maxx id;
		std::cin >> opt >> id;

		if (opt == park) std::cout << Park(id) << '\n';
		else Leave(id);
	}
}


int main() {
	freopen("parking.inp", "r", stdin);
	freopen("parking.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}