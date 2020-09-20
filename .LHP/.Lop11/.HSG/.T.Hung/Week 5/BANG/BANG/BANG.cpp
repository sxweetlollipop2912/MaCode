#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

//#define maxN 1000001
#define mrow 0
#define mcol 1
#define row(x) ((x) / n)
#define col(x) ((x) % n)
#define moves(x, y) (((y) + n - (x)) % n)
#define moveto(x, op, m) ((op) == mrow ? (((((x) % n) + (m)) % n) + (n * row(x))) : (((((x) / n) + (m)) % n) * n + col(x)))
#define opt first
#define idx second.first
#define cnt second.second
#define moveT(op, id, cn) move_t(op, std::pair <maxn, maxn>(id, cn))

typedef long maxn;
typedef int maxk;
typedef std::pair <bool, std::pair <maxn, maxn>> move_t;

maxn n;
maxk k;
std::vector <move_t> list;


void Prepare() {
	std::cin >> n >> k;
}


maxn Move(const maxn x, const maxn r, const maxn c) {
	list.push_back(moveT(mrow, row(x), moves(col(x), c)));
	list.push_back(moveT(mcol, c, moves(row(x), r)));
	return moves(col(x), c) + moves(row(x), r);
}


maxn Move_to(const maxn x, const move_t m) {
	if ((m.opt == mrow && m.idx != row(x)) || (m.opt == mcol && m.idx != col(x))) return x;
	return moveto(x, m.opt, m.cnt);
}


void Process() {
	while (k--) {
		maxn x, r, c;
		std::cin >> x >> r >> c, --x, --r, --c;
		for (maxk i = 0; i < list.size(); i++) x = Move_to(x, list[i]);
		std::cout << Move(x, r, c) << '\n';
	}
}


int main() {
	//freopen("bang.inp", "r", stdin);
	//freopen("bang.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}