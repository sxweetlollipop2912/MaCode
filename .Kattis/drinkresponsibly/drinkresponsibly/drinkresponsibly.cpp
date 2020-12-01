// AC Kattis
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define maxD 9
#define maxM 1002
#define maxU 1202
#define money first
#define unit second

typedef int maxn, maxa;
typedef std::pair <maxa, maxa> p_t;
typedef std::string str;

maxn n;
maxa M, U, u[maxD], c[maxD], f[maxM][maxU][maxD], bought[maxD];
str name[maxD];
bool done[maxM][maxU];
std::vector <p_t> st;


void Prepare() {
	double d;
	std::cin >> d, M = d * 100;
	std::cin >> d, U = d * 10 * 6;
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		std::cin >> name[i];

		maxa s; str l;
		std::cin >> s >> l;

		if (l == "1/1") u[i] = s * 10 * 6;
		if (l == "1/2") u[i] = s * 10 * 3;
		if (l == "1/3") u[i] = s * 10 * 2;

		std::cin >> d, c[i] = d * 100;
	}
}


bool Process() {
	st.push_back(p_t(0, 0)); done[0][0] = 1;

	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < st.size(); j++) {
		maxa m = st[j].money + c[i], un = st[j].unit + u[i];
		if (m > M || un > U || done[m][un]) continue;
		done[m][un] = 1;
		f[m][un][i] = f[st[j].money][st[j].unit][i] + 1;
		st.push_back(p_t(m, un));
	}

	if (!done[M][U]) return 0;

	for (maxn i = n - 1; i >= 0; i--) {
		bought[i] = f[M][U][i];
		M -= c[i] * bought[i], U -= u[i] * bought[i];
	}
	for (maxn i = 0; i < n; i++)
		if (bought[i]) std::cout << name[i] << ' ' << bought[i] << '\n';
	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "IMPOSSIBLE";
}