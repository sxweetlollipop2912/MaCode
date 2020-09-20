#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 200001
#define maxA 1000000001
#define maxQ 200001
#define rec 1
#define pay 2
#define none -1

typedef long maxn, maxa, maxq;
typedef int maxo;

struct info {
	maxo opt;
	maxn target;
	maxa amount;
}; 
void setInfo(info& inf, const maxo opt, const maxn  target, const maxa amount) {
	inf.opt = opt, inf.target = target, inf.amount = amount;
}

maxn n;
maxa b[maxN];
maxq q, N;
std::vector <info> Q;


void Prepare() {
	std::cin >> n;

	Q.resize(n);
	for (maxn i = 0; i < n; i++) {
		maxa a;
		std::cin >> a;
		setInfo(Q[i], rec, i, a);
	}

	std::cin >> q;
	N = n + q;

	Q.resize(N);
	for (maxn i = n; i < N; i++) {
		maxo opt; maxn t = 1; maxa a;
		std::cin >> opt;
		if (opt == rec) std::cin >> t;
		std::cin >> a;
		setInfo(Q[i], opt, --t, a);
	}

	std::fill(b, b + n, none);
}


void Process() {
	maxa mxp = 0;
	
	for (maxq i = N - 1; i >= 0; i--) {
		if (Q[i].opt == pay) mxp = std::max(mxp, Q[i].amount);
		else if (b[Q[i].target] == none) b[Q[i].target] = std::max(Q[i].amount, mxp);
	}

	for (maxn i = 0; i < n; i++) std::cout << b[i] << ' '; 
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}