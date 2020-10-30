// AC
#include <iostream>
#include <algorithm>
#include <string>

#define maxN 100003

typedef long maxn;

maxn n, z[maxN], cnt[maxN], res;
std::string s;


void Prepare() {
    std::cin >> s;
    n = s.size();
}


void Process() {
    z[0] = 0;
    for (maxn l = 0, r = -1, i = 1; i < n; i++) {
        z[i] = 0;
        if (i <= r)
            z[i] = std::min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] -1;
    }

    z[0] = n, res = 0;
    for (maxn i = n - 1; i >= 0; i--) {
        if (i + z[i] == n)
            ++res;
        ++cnt[1], --cnt[z[i] + 1];
        //std::cout << "Z " << i << ' ' << z[i] << '\n';
    }

    std::cout << res << '\n';
    for (maxn i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1] + cnt[i];
        if (n - i + z[n - i] == n) 
            std::cout << i << ' ' << cnt[i] << '\n';
    }
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}