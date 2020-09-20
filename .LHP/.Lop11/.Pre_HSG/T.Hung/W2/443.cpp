// AC UVa
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 5843
#define maxA (maxn)2000000001

typedef long long maxn;

maxn num[maxN], n;


void Process() {
	num[0] = 1;
	for (maxn i = 1; i <= n; i++) {
		num[i] = maxA;
		num[i] = std::min(num[i], num[std::upper_bound(num, num + i, num[i - 1] / 2) - num] * 2);
		num[i] = std::min(num[i], num[std::upper_bound(num, num + i, num[i - 1] / 3) - num] * 3);
		num[i] = std::min(num[i], num[std::upper_bound(num, num + i, num[i - 1] / 5) - num] * 5);
		num[i] = std::min(num[i], num[std::upper_bound(num, num + i, num[i - 1] / 7) - num] * 7);
	}
	//std::cout << num[n] << '\n';
}


void Output(const maxn num) {
	std::cout << "The " << n;
	if (n % 100 >= 11 && n % 100 <= 13) std::cout << "th";
	else if (n % 10 == 1) std::cout << "st";
	else if (n % 10 == 2) std::cout << "nd";
	else if (n % 10 == 3) std::cout << "rd";
	else std::cout << "th";
	std::cout << " humble number is " << num << ".\n";
}


int main(){
	freopen("443.inp", "r", stdin);
	freopen("443.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) {
		Process();
		Output(num[n - 1]);
	}
}