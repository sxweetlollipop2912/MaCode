#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 100001
#define maxA 1000002
#define maxR 100001
#define none 0
#define low first
#define high second

typedef long maxa;
typedef long long maxn;
typedef std::pair <maxa, maxa> ranget;

maxn n, res;
ranget X[maxA], Y[maxA];
std::vector <maxa> Listx, Listy, listy, Xaxis[maxA];


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		maxa x, y;
		std::cin >> x >> y;
		Xaxis[x].push_back(y);

		if (X[x].low == none) {
			X[x].low = X[x].high = y;
			Listx.push_back(x);
		}
		else {
			X[x].low = std::min(X[x].low, y);
			X[x].high = std::max(X[x].high, y);
		}

		if (Y[y].low == none) {
			Y[y].low = Y[y].high = x;
			Listy.push_back(y);
			listy.push_back(y);
		}
		else {
			Y[y].low = std::min(Y[y].low, x);
			Y[y].high = std::max(Y[y].high, x);
		}
	}

	std::sort(Listx.begin(), Listx.end());
	std::sort(Listy.begin(), Listy.end());
}


//**************// FENWICK_TREE //*************************************************

maxn bit[maxN];

void InitBit() {
	std::fill(bit, bit + Listy.size() + 1, 0);
}


void Update(maxn id) {
	while (id <= Listy.size()) 
		++bit[id], id += (id & (-id));
}

maxn Get(maxn id) {
	maxn re = 0;
	while (id > 0)
		re += bit[id], id -= (id & (-id));
	return re;
}

//*********************************************************************************


bool cmp1(const maxn &x, const maxn &y) {
	return Y[x].low < Y[y].low;
}

void Process1() {
	std::sort(listy.begin(), listy.end(), cmp1);
	maxn j = listy.size() - 1;

	InitBit();
	for (maxn i = Listx.size() - 1; i >= 0; i--) {
		maxa x = Listx[i];
		while (j >= 0 && Y[listy[j]].low >= x) {
			Update(std::lower_bound(Listy.begin(), Listy.end(), listy[j]) - Listy.begin() + 1);
			--j;
		}
		maxn idlo = std::lower_bound(Listy.begin(), Listy.end(), X[x].low) - Listy.begin();
		maxn idhi = std::lower_bound(Listy.begin(), Listy.end(), X[x].high) - Listy.begin();
		
		res += (idhi - idlo + 1) - Get(idhi + 1) + Get(idlo + 1) - (Y[X[x].low].low >= x);

		for (maxn ii = 0; ii < Xaxis[x].size(); ii++) 
			res -= Y[Xaxis[x][ii]].low < x;
	}
}


bool cmp2(const maxn& x, const maxn& y) {
	return Y[x].high < Y[y].high;
}

void Process2() {
	std::sort(listy.begin(), listy.end(), cmp2);
	maxn j = 0;

	InitBit();
	for (maxn i = 0; i < Listx.size(); i++) {
		maxa x = Listx[i];
		while (j < listy.size() && Y[listy[j]].high < x) {
			Update(std::lower_bound(Listy.begin(), Listy.end(), listy[j]) - Listy.begin() + 1);
			++j;
		}
		res -= Get(std::lower_bound(Listy.begin(), Listy.end(), X[x].high) - Listy.begin() + 1);
		res += Get(std::lower_bound(Listy.begin(), Listy.end(), X[x].low) - Listy.begin() + 1);
		res -= (Y[X[x].low].high < x);
	}
}


int main() {
	Prepare();
	Process1();
	Process2();
	std::cout << res;
}