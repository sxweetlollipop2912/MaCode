#include <iostream>
#include <algorithm>
#include <fstream>

#define maxN 51

typedef int maxn;
typedef long long maxa;

maxn n;
maxa f[maxN], k;


void Prepare() {
    std::cin >> n >> k;
    
    f[0] = f[1] = 1;
    for(maxn i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
}


void Process() {
    maxn i = n;
    
    while (i > 1) {
        if (k <= f[i - 2]) i -= 2;
        else i-= 1, k -= f[i - 2];
    }
    
    if (!i) std::cout << 'a';
    else std::cout << 'b';
}


int main() {
    //freopen("fibo","r",stdin);
    //freopen("fibo","w",stdout);
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}
