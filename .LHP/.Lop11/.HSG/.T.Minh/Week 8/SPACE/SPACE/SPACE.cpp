#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>

#define maxM 1001
#define maxN 1001
#define X first
#define Y second.first
#define Z second.second
#define newCo(x, y, z) co_t(x, std::make_pair(y, z))
#define sqr(x) ((x) * (x))

typedef long maxn;
typedef long long maxa, maxr;
typedef std::pair <maxa, std::pair <maxa, maxa>> co_t;

const co_t OoO = newCo(0, 0, 0);

maxn P, n;
co_t co[maxM], sta[maxN];
maxa r[maxM], D, res;
maxr kc[maxM];
bool taken[maxM];


void Prepare() {
	std::cin >> P;
	for (maxn i = 0; i < P; i++) std::cin >> co[i].X >> co[i].Y >> co[i].Z >> kc[i] >> r[i];

	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> sta[i].X >> sta[i].Y >> sta[i].Z;

	std::cin >> D;
}


co_t vect(const co_t& A, const co_t& B) { // AB
	return newCo(B.X - A.X, B.Y - A.Y, B.Z - A.Z);
}

co_t cp(const co_t& A, const co_t& B) {
	return newCo(A.Y * B.Z - A.Z * B.Y, A.Z * B.X - A.X * B.Z, A.X * B.Y - A.Y * B.X);
}

maxa dp(const co_t& A, const co_t& B) {
	return A.X * B.X + A.Y * B.Y + A.Z * B.Z;
}

co_t sub(const co_t& A, const co_t& B) { // A - B
	return newCo(A.X - B.X, A.Y - B.Y, A.Z - B.Z);
}

maxa dist_2p(const co_t& A, const co_t& B) {
	return (sqr(A.X - B.X) + sqr(A.Y - B.Y) + sqr(A.Z - B.Z));
}

maxa dist_pl(const co_t& O, const co_t& A, const co_t& B) {
	return dist_2p(OoO, cp(sub(O, A), sub(O, B))) / dist_2p(OoO, sub(B, A));
}

maxa Dist_ps(const co_t& O, const co_t& A, const co_t& B) {
	if (dp(vect(A, O), vect(A, B)) < 0) return ceil(sqrt(dist_2p(O, A)));
	if (dp(vect(B, O), vect(B, A)) < 0) return ceil(sqrt(dist_2p(O, B)));
	return ceil(sqrt(dist_pl(O, A, B)));
}


void Process() {
	for (maxn i = 1; i < n; i++) for (maxn p = 0; p < P; p++) {
		if (taken[p] || Dist_ps(co[p], sta[i - 1], sta[i]) > D + r[p]) continue;
		res += kc[p], taken[p] = 1;
		//std::cout << p << ' ' << i - 1 << ' ' << i << ' ' << Dist_ps(co[p], sta[i - 1], sta[i]) << '\n';
	}
	std::cout << res;
	//std::cout << '\n' << Dist_ps(OoO, newCo(0, 1, 2), newCo(0, 1, -100));
}


int main() {
	//freopen("space.inp", "r", stdin);
	//freopen("space.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}