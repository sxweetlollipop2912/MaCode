#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>

#define maxN 20001
#define maxA 1000001
#define maxT 2000001

typedef long maxn, maxa;

maxa a[maxN], b[maxN];
maxn na, nb, k, cnt[maxN];

struct info {
    maxa t;
    maxn id;
};


info newInfo(maxa t, maxn id) {
    info re;
    re.t = t; re.id = id;
    return re;
}


// ***********************************************************
// **** PRIORITY QUEUE _ SET UP ******************************

class cmp {
public:
	bool operator() (const info p1, const info p2) {
		return p1.t > p2.t;
	}
};
std::priority_queue < info, std::vector <info>, cmp > Queue;

// ***********************************************************


void Prepare() {
    std::cin >> na >> nb >> k;

    for(maxn i = 0; i < na; i++) std::cin >> a[i];
    for(maxn i = 0; i < nb; i++) std::cin >> b[i];

    std::sort(b, b + nb);

    for(maxn i = 0; i < na; i++) {
        Queue.push(newInfo(a[i] + b[0], i));
        //std::cout << a[i] << ' ' << b[0] << ' ' << i << '\n';
        //std::cout << Queue.top().t << ' ' << Queue.top().id << '\n';
        cnt[i] = 0;
    }
}


void Process() {
    maxa re = 0;
    while (k--) {
        re = Queue.top().t;
        //std::cout << re << '\n';
        maxn id = Queue.top().id;
        Queue.pop();
        if (++cnt[id] < nb) Queue.push(newInfo(a[id] + b[cnt[id]], id));
    }
    std::cout << re;
}



int main() {
    freopen("sohangk1.inp","r",stdin);
    freopen("sohangk1.out","w",stdout);
    Prepare();
    Process();
}
