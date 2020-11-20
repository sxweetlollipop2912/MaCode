#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
 
#define maxN 1000002
 
typedef long maxn;
typedef std::string str;
 
maxn n, z[maxN];
str s;
 
 
void Prepare() {
    std::cin >> s;
    n = s.size();
}
 
 
bool Check(const maxn len) {
    for(maxn i = 0; i < n; i += len) if (i + z[i] < n && z[i] < len) return 0;
    return 1;
}
 
 
void Process() {
    z[0] = 1;
    for(maxn i = 1, l = 0, r = 0; i < n; i++) {
        z[i] = 0;
        if (i <= r) z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r)
            r = i + z[i] - 1, l = i;
    }
    z[0] = n;
 
    for(maxn len = 1; len <= n; len++)
        if (Check(len)) std::cout << len << ' ';
}
 
 
int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
 
    Prepare();
    Process();
}