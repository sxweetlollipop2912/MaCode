#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 5001

typedef long maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], res;
std::priority_queue <maxa, std::vector <maxa>, std::greater <maxa> > pq;


void Prepare() {
    for(maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
    pq = std::priority_queue <maxa, std::vector <maxa>, std::greater <maxa> >();
    for(maxn i = 0; i < n; i++) pq.push(a[i]);

    res = 0;
    while (pq.size() != 1) {
        maxa x1 = pq.top(); pq.pop();
        maxa x2 = pq.top(); pq.pop();
        res += x1 + x2;
        pq.push(x1 + x2);
    }
    
    std::cout << res << '\n';
}


int main() {
    while (std::cin >> n && n) {
        Prepare();
        Process();
    }
}