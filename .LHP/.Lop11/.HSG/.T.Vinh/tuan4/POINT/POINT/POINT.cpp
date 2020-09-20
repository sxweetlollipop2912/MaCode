#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_map>

#define maxN 300001
#define maxK 100001
#define x first
#define y second
#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second

typedef long maxn, maxk;
typedef long maxa;
typedef std::pair <maxa, maxa> co_t;
typedef std::pair <co_t, co_t> rec_t;

maxn n;
maxk K;
co_t point[maxN];
rec_t rec[maxK];
std::unordered_map <maxa, std::vector <maxa> > mx, my;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> point[i].x >> point[i].y;
	std::sort(point, point + n);
	for (maxn i = 0; i < n; i++) mx[point[i].x].push_back(point[i].y), my[point[i].y].push_back(point[i].x);

	std::cin >> K;
	for (maxk i = 0; i < K; i++) std::cin >> rec[i].x1 >> rec[i].y1 >> rec[i].x2 >> rec[i].y2;
}


maxn Count(std::vector <maxa>& v, const maxa l, const maxa r) {
	return l <= r ? std::upper_bound(v.begin(), v.end(), r) - std::lower_bound(v.begin(), v.end(), l) : 0;
}


void Process() {
	for (maxk k = 0; k < K; k++) {
		maxn cnt = Count(mx[rec[k].x1], rec[k].y1, rec[k].y2) + Count(mx[rec[k].x2], rec[k].y1, rec[k].y2);
		cnt += Count(my[rec[k].y1], rec[k].x1 + 1, rec[k].x2 - 1) + Count(my[rec[k].y2], rec[k].x1 + 1, rec[k].x2 - 1);
		std::cout << cnt << '\n';
	}
}


int main() {
	//freopen("point.inp", "r", stdin);
	//freopen("point.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}