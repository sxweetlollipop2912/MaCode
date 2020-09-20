#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 10000002

typedef long maxa;
typedef long long maxr;

maxa A, B, lp[maxN];
maxr res, t[maxN];
std::vector <maxa> pr;


void Prepare() {
	std::cin >> A >> B;
}


void Process() {
	res = 0;

	t[1] = 1; lp[1] = 1;
	for (maxa i = 1; i <= B; i++) {
		if (!lp[i]) {
			lp[i] = i;
			t[i] = (maxr)i + (maxr)1;
			pr.push_back(i);
		}
		for (maxa j = 0; j < pr.size() && pr[j] <= lp[i] && (maxr)i * (maxr)pr[j] <= (maxr)B; j++) {
			lp[i * pr[j]] = pr[j];
			maxr tmp = t[i];
			if (pr[j] == lp[i]) 
				tmp = t[i] - t[i / pr[j]];
			t[i * pr[j]] = tmp * (maxr)pr[j] + t[i];
		}

		if (i >= A) res += abs((maxr)i - (t[i] - (maxr)i));
	}

	std::cout << res;
}


int main() {
	//freopen("hhh.inp", "r", stdin);
	//freopen("hhh.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}