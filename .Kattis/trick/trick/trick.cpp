#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

typedef long maxa;
typedef double maxx;

maxx x, f[8];
std::vector <maxa> res;


void Prepare() {
	std::cin >> x;
	f[0] = 1;
	for (int i = 1; i < 8; i++) f[i] = 10 * f[i - 1];
}


void Gen(const int len) {
	for (maxx a = 1; a < 10; a++) {
		maxx b = a * (f[len - 1] * x - 1) / (10 - x);
		if (b > f[len - 1] || b != floor(b)) continue;
		res.push_back(a * f[len - 1] + b);
	}
}


void Process() {
	for (int len = 1; len < 9; len++) Gen(len);
	std::sort(res.begin(), res.end());

	if (res.empty()) std::cout << "No solution";
	else for (maxa i = 0; i < res.size(); i++) std::cout << res[i] << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}