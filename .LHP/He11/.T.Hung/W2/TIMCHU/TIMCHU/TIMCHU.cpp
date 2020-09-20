#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define maxN 5001
#define maxC 4
#define C 3
#define num(c) ((c) - 'a')

typedef int maxn;
typedef std::string str;

maxn n, av[maxC], l[maxC];
str s;


void Prepare() {
	str ss;
	std::cin >> ss >> s;
	
	for (maxn i = 0; i < ss.size(); i++)
		++l[num(ss[i])], ++av[num(ss[i])];
}


void Process() {
	for (maxn i = 0; i < s.size(); i++) {
		int c = num(s[i]);
		if (c != 0 && av[0] && ((av[0] - 1) + (av[1]) >= l[2]) && (((av[0] - 1) + (av[2]) >= l[1])))
	}
}