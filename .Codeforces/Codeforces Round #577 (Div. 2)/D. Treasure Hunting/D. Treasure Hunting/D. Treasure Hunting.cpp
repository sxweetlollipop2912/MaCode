#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 200001
#define row first
#define col second
#define le 0
#define ri 1

typedef long long maxn;
typedef std::pair <maxn, maxn> co;

maxn R, C, t, s, res, tr[maxN][2];
std::vector <maxn> safe;


void Prepare() {
	std::cin >> R >> C >> t >> s;

	for (maxn i = 0; i < t; i++) {
		maxn r, c;
		std::cin >> r >> c;
		tr[r][le] = !tr[r][le] ? c : std::min(tr[r][le], c);
		tr[r][ri] = std::max(tr[r][ri], c);
	}
	if (!tr[1][le]) tr[1][le] = tr[1][ri] = 1;

	safe.resize(s);
	for (maxn i = 0; i < s; i++)
		std::cin >> safe[i];

	std::sort(safe.begin(), safe.end());
}


maxn Move(const co cos, const co cot) {
	maxn cl = std::min(cos.col, cot.col), cr = cos.col + cot.col - cl;
	maxn fr = std::lower_bound(safe.begin(), safe.end(), cl) - safe.begin();

	if (fr == safe.size()) return cl - safe.back() + cr - safe.back() + cot.row - cos.row;
	else if (safe[fr] <= cr) return safe[fr] - cl + cr - safe[fr] + cot.row - cos.row;
	else if (fr == 0) return safe[fr] - cl + safe[fr] - cr + cot.row - cos.row;
	
	return std::min(safe[fr] - cl + safe[fr] - cr + cot.row - cos.row, cl - safe[fr - 1] + cr - safe[fr - 1] + cot.row - cos.row);
}


void Process() {
	maxn l[2], r[2];
	bool p = 0;
	r[p] = tr[1][ri] - 1, l[p] = r[p] + tr[1][ri] - tr[1][le];

	maxn pr = 1;
	for (maxn cr = 2; cr <= R; cr++) {
		if (!tr[cr][le]) continue;

		p = !p;
		maxn go = tr[cr][ri] - tr[cr][le];

		r[p] = std::min(Move(co(pr, tr[pr][le]), co(cr, tr[cr][le])) + l[!p], Move(co(pr, tr[pr][ri]), co(cr, tr[cr][le])) + r[!p]) + go;
		l[p] = std::min(Move(co(pr, tr[pr][le]), co(cr, tr[cr][ri])) + l[!p], Move(co(pr, tr[pr][ri]), co(cr, tr[cr][ri])) + r[!p]) + go;
		pr = cr;
	}

	std::cout << std::min(r[p], l[p]);
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}