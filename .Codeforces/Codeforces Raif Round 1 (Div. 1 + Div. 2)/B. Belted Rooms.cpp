//B. Belted Rooms
#include <iostream>
#include <algorithm>
#include <string>

#define prev(x) (((x) + n - 1) % n)

typedef long maxn;

maxn n, res;
std::string a;


void Prepare() {
    std::cin >> n >> a;
}


void Process() {
    bool through = 1; 
    char dir = a[0];
    for(maxn i = 1; i < n && dir == '-'; i++) dir = a[i];

    for(maxn i = 0; i < n; i++) if (a[i] != dir && a[i] != '-') through = 0;

    res = 0;
    for(maxn i = 0; i < n; i++) {
        if (a[i] == '-' || a[prev(i)] == '-') ++res;
        else if (through) ++res;
    }
    
    std::cout << res << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}