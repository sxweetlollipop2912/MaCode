#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 32002
#define maxA 2003
#define idlr(x, y) ((x) - (y) + 1000)
#define idrl(x, y) ((x) + (y))
#define X first
#define Y second

typedef int maxn, maxa;
typedef std::pair <maxa, maxa> co_t;

maxn n;
co_t p[maxN];
maxa minX = maxA, maxX = 0, minY = maxA, maxY = 0;
bool lr[maxA], rl[maxA];
std::vector <co_t> res;


void Prepare() {
	std::cin >> n;
	
	for (maxn i = 0; i < n; i++) {
		std::cin >> p[i].X >> p[i].Y;
		lr[idlr(p[i].X, p[i].Y)] = rl[idrl(p[i].X, p[i].Y)] = 1;

		//std::cout << idlr(p[i].X, p[i].Y) << ' ' << idrl(p[i].X, p[i].Y) << '\n';

		minX = std::min(minX, p[i].X), maxX = std::max(maxX, p[i].X);
		minY = std::min(minY, p[i].Y), maxY = std::max(maxY, p[i].Y);
	}
}


void Process() {
	maxa lru = idlr(minX, maxY), lrd = idlr(maxX, minY), rlu = idrl(maxX, maxY), rld = idrl(minX, minY);
	//std::cout << lru << ' ' << lrd << ' ' << rlu << ' ' << rld << '\n';

	while (!lr[lru]) ++lru; while (!lr[lrd]) --lrd;
	while (!rl[rlu]) --rlu; while (!rl[rld]) ++rld;

	co_t cur; 
	cur.Y = minY, cur.X = cur.Y + lrd - 1000;
	res.push_back(cur);

	cur.X = maxX, cur.Y = cur.X - lrd + 1000;
	if (cur.Y != minY) res.push_back(cur);

	cur.X = maxX, cur.Y = rlu - cur.X;
	if (idlr(cur.X, cur.Y) != lrd) res.push_back(cur);

	cur.Y = maxY, cur.X = rlu - cur.Y;
	if (cur.X != maxX) res.push_back(cur);

	cur.Y = maxY, cur.X = cur.Y + lru - 1000;
	if (idrl(cur.X, cur.Y) != rlu) res.push_back(cur);

	cur.X = minX, cur.Y = cur.X - lru + 1000;
	if (cur.Y != maxY) res.push_back(cur);

	cur.X = minX, cur.Y = rld - cur.X;
	if (idlr(cur.X, cur.Y) != lru) res.push_back(cur);

	cur.Y = minY, cur.X = rld - cur.Y;
	if (cur.X != minX && idlr(cur.X, cur.Y) != lrd) res.push_back(cur);

	std::cout << res.size() << '\n';
	for (maxn i = 0; i < res.size(); i++) std::cout << res[i].X << ' ' << res[i].Y << '\n';
}


int main() {
	//freopen("princess.inp", "r", stdin);
	//freopen("princess.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}