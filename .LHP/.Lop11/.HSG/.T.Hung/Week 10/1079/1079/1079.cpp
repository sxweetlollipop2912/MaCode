#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 9
#define maxA 1441
#define MAX 1440
#define left second
#define right first

typedef int maxn, maxa;
typedef std::pair <maxa, maxa> in_t;

maxn n;
in_t in[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> in[i].left >> in[i].right;
	std::sort(in, in + n);
}