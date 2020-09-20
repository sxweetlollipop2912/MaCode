// AC Kattis
#include "pch.h"
#include <iostream>
#include <string>
#include <set>

#define maxN 1001
#define entry "entry"
#define exit "exit"
#define anom " (ANOMALY)"

typedef int maxn;
typedef std::string str;

maxn n;
std::set <str> set;


void Prepare() {
	std::cin >> n;
}


void Enter(const str &per) {
	std::cout << per << " entered";
	if (set.find(per) == set.end()) set.insert(per);
	else std::cout << anom;
	std::cout << '\n';
}


void Exit(const str &per) {
	std::cout << per << " exited";
	if (set.find(per) != set.end()) set.erase(per);
	else std::cout << anom;
	std::cout << '\n';
}


void Process() {
	while (n--) {
		str opt, per;
		std::cin >> opt >> per;
		if (opt == entry) Enter(per);
		else Exit(per);
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}