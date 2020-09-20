#include <iostream>
#include <algorithm>
#include <cstdio>

//#define maxN 64
#define num1(x) (ll)(((ll)1 << (x)) - (ll)1)

typedef unsigned long long ll;

ll a, b, res;


void Prepare() {
	std::cin >> a >> b;
}


void Process() {
	for (ll i1 = 1, x = 0; num1(i1) <= b; i1++, ++res) for(ll i0 = 1; (num1(i1) << i0) <= b; i0++, x = 0, --res) for(ll k = 1; ((x << i1) + num1(i1)) <= b; k++) {
		x = ((x << i1) + num1(i1)) << i0;
		res += (ll)1 + (ll)(x <= b);
		//std::cout << i1 << ' ' << i0 << ' ' << x << ' ' << res << '\n';
	}
	b = a - 1; //std::cout << '\n';
	for (ll i1 = 1, x = 0; num1(i1) <= b; i1++, --res) for (ll i0 = 1; (num1(i1) << i0) <= b; i0++, x = 0, ++res) for (ll k = 1; ((x << i1) + num1(i1)) <= b; k++) {
		x = ((x << i1) + num1(i1)) << i0;
		res -= (ll)1 + (ll)(x <= b);
		//std::cout << i1 << ' ' << i0 << ' ' << x << ' ' << res << '\n';
	}
	std::cout << res;
}


int main() {
	//freopen("sodep.inp", "r", stdin);
	//freopen("sodep.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}