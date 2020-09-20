#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

#define maxN 1000002
#define maxS 4000005
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)
#define mid(l, r) (((l) + (r)) / 2)
#define open 1
#define close (-1)
#define Sum(i) Get_Min(0, n, 0, i, i)

typedef long maxn;
typedef std::string str;

str s;
maxn n, Q, x[maxN], y[maxN], laz[maxS], res[maxN], br[maxN], seg[maxS];
char opt[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> s >> Q;
	n = s.size();

	for (maxn i = 1; i <= Q; i++) {
		std::cin >> opt[i] >> x[i];
		if (opt[i] == 'Q') std::cin >> y[i];
		else if (opt[i] == 'U') {
			ad[x[i] - 1].push_back(i + 1);
		}
	}

	for (maxn i = 1; i <= n; i++) br[i] = br[i - 1] + (s[i - 1] == '(' ? open : close);
}


void Build(const maxn Ls, const maxn Rs, const maxn ids) {
	if (Ls == Rs) seg[ids] = br[Ls];
	else {
		Build(Ls, mid(Ls, Rs), cle(ids)); Build(mid(Ls, Rs) + 1, Rs, cri(ids));
		seg[ids] = std::min(seg[cle(ids)], seg[cri(ids)]);
	}
	laz[ids] = 0;
}


void Apply_Laz(const maxn ids) {
	seg[ids] += laz[ids];
	laz[cle(ids)] += laz[ids], laz[cri(ids)] += laz[ids], laz[ids] = 0;
}


void Update(const maxn Ls, const maxn Rs, const maxn ids, const maxn L, const maxn R, const maxn val) {
	if (Ls > Rs || Ls > R || Rs < L) return;
	if (Ls < L || Rs > R) {
		Apply_Laz(ids);
		Update(Ls, mid(Ls, Rs), cle(ids), L, R, val); Update(mid(Ls, Rs) + 1, Rs, cri(ids), L, R, val);
		seg[ids] = std::min(seg[cle(ids)], seg[cri(ids)]);
	}
	else {
		laz[ids] += val;
		Apply_Laz(ids);
	}
}


maxn Get_Min(const maxn Ls, const maxn Rs, const maxn ids, const maxn L, const maxn R) {
	if (Ls > Rs || Ls > R || Rs < L) return maxN;
	Apply_Laz(ids);
	if (Ls < L || Rs > R) return std::min(Get_Min(Ls, mid(Ls, Rs), cle(ids), L, R), Get_Min(mid(Ls, Rs) + 1, Rs, cri(ids), L, R));
	return seg[ids];
}


void Run(const maxn q) {
	maxn i;
	for (i = q; i <= Q; i++) {
		if (opt[i] == 'C') {
			if (br[x[i]] == 1)
				Update(0, n, 0, x[i], n, -2);
			else
				Update(0, n, 0, x[i], n, 2);;
			br[x[i]] = -br[x[i]];
		}
		else if (opt[i] == 'Q') {
			maxn s = Sum(x[i] - 1), tmp_mn = Get_Min(0, n, 0, x[i], y[i]) - s, tmp_mx = Sum(y[i]) - s;
			if (tmp_mn < 0) res[i] -= tmp_mn, tmp_mx -= tmp_mn;
			if (tmp_mx > 0) res[i] += tmp_mx;
		}
		for (maxn j = 0; j < ad[i].size(); j++) Run(ad[i][j]);

		if (opt[i] == 'U') break;
	}

	for (i = i - 1; i >= q; i--) {
		if (opt[i] != 'C') continue;
		if (br[x[i]] == 1) 
			Update(0, n, 0, x[i], n, -2);
		else 
			Update(0, n, 0, x[i], n, 2);
		br[x[i]] = -br[x[i]];
	}
}


void Process() {
	Build(0, n, 0);
	for (maxn i = 1; i <= n; i++) br[i] = s[i - 1] == '(' ? open : close;

	Run(0);
	for (maxn i = 1; i <= Q; i++) if (opt[i] == 'Q') std::cout << res[i] << '\n';
}


int main() {
	//freopen("fixstr.inp", "r", stdin);
	//freopen("fixstr.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}