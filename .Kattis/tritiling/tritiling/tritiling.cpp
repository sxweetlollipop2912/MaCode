#include <iostream>
#include <algorithm>
#include <cstring>

#define maxN 31
#define maxB 9
#define M 3
#define B 8

typedef int maxn;
typedef long long maxa;

maxn N, sp[8][4] = { { 3,1,4,7 },{ 2,0,6,0 },{ 1,5,0,0 },{1,4,0,0 },{ 2,0,3,0 },{ 1,2,0,0 },{ 1,1,0,0 },{ 1,0,0,0 } };
maxa f[maxN][maxB];


void Process() {
	for (maxn i = 0; i < N; i++) std::fill(f[i], f[i] + maxB, 0);

	f[0][1] = f[0][4] = f[0][7] = 1;

	for (maxn i = 1; i < N; i++) for (maxn b = 0; b < B; b++) for(maxn ib = 1; ib <= sp[b][0]; ib++) {
		f[i][sp[b][ib]] += f[i - 1][b];
	}

	if (!N) std::cout << "1\n";
	else std::cout << f[N - 1][0] << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> N && N != -1) 
		Process();
}