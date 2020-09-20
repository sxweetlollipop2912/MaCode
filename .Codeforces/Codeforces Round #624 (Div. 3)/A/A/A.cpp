#include <iostream>
#include <algorithm>
#include <map>

#define maxN 200002
#define X first
#define V second

typedef long long maxn, maxa;
typedef std::pair <maxa, maxa> p_t;

maxn n, cnt[maxN];
p_t a[maxN];
maxa val[maxN], res;
std::map <long, long> Num;


void RR() {
	maxn Cnt = 0;
	for (maxn i = 1; i <= n; ++i) Num[a[i].V] = 0;
	for (auto& x : Num) x.second = ++Cnt;
	for (int i = 1; i <= n; ++i) a[i].V = Num[a[i].V];
}


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i].X;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i].V;

	std::sort(a, a + n + 1);
	RR();
}


void Update(long long bit[], maxn id, long long val) {
	while (id <= n) bit[id] += val, id += (id & (-id));
}

long long Sum(long long bit[], maxn id) {
	long long re = 0;
	while (id) re += bit[id], id -= (id & (-id));
	return re;
}


void Process() {
	for (maxn i = 1; i <= n; i++) {
		res += (Sum(val, a[i].V) + Sum(cnt, a[i].V) * a[i].X);
		Update(val, a[i].V, -a[i].X);
		Update(cnt, a[i].V, 1);
		//std::cout << res << ' ' << a[i].X << ' ' << a[i].V << '\n';
	}
	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}