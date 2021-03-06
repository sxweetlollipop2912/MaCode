#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

#define maxMN 20
#define maxA 3200
#define minA -3200
#define maxS 1280000 // 3200
#define minS -1280000

typedef int maxn, maxa;

maxa a[maxMN][maxMN];
maxn m, n, k;
long t[maxMN], re, S;
bool ii[maxMN]; 
//maxn lre[maxMN], l[maxMN];

void Prepare() {
	//freopen("TONGCON.inp", "r", stdin);
	//freopen("TONGCON.out", "w", stdout);
	std::cin >> m >> n >> k;

	for (maxn i = 0; i < m; i++)
		for (maxn j = 0; j < n; j++)
			std::cin >> a[i][j];

	t[n] = 0;
	//std::fill(l, l + n, -1);
	//std::fill(lre, lre + n, -1);
}


void Init() {
	maxa maxT[maxMN];
	std::fill(maxT, maxT + k, minA);

	for (maxn j = n - 1; j >= n - k; j--) {
		maxa max_all = a[0][j], maxi = minA;
		maxn li = -1;

		for (maxn i = 0; i < m; i++) {
			max_all = std::max(max_all, a[i][j]);

			if (!ii[i] && a[i][j] > maxi) {
				maxi = a[i][j];
				li = i;
			}
		}

		//lre[j] = li;
		ii[li] = 1;
		re += maxi;

		t[j] = t[j + 1] + max_all;
		maxT[n - j - 1] = max_all;
	}

	std::fill(ii, ii + n, 0);

	
	maxn p = k - 1;
	for (maxn j = n - k - 1; j >= 0; j--) {
		
		p = (p + 1) % k;
		maxa max_all = a[0][j];
		
		for (maxn i = 0; i < m; i++) 
			max_all = std::max(max_all, a[i][j]);
		
		t[j] = t[j + 1];
		if (maxT[p] >= max_all) continue;
		
		t[j] = t[j + 1] + max_all - maxT[p];
		maxT[p] = max_all;
	}
}


/*void Save() {
	for (int i = 0; i < n; i++) 
		lre[i] = l[i];
}*/


void Try(maxn j, maxn count) {
	
	if (count + (n - j) < k || count > k || S + t[j] <= re) return;
	if (count == k) {
		if (S <= re) return;
		re = S;
		//Save();
		return;
	}

	for (int i = 0; i < m; i++) {
		if (ii[i]) continue;
		ii[i] = 1;
		//l[j] = i;
		S += a[i][j];
		Try(j + 1, count + 1);
		//l[j] = -1;
		ii[i] = 0;
		S -= a[i][j];
	}
}


int main() {
	Prepare();
	Init();
	Try(0, 0);
	std::cout << re << '\n';
	/*for (int j = 0; j < n; j++)
		if (lre[j] > -1)std::cout << a[lre[j]][j] << ' ';*/
}