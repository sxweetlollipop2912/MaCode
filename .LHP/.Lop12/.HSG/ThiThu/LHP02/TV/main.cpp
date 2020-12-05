#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>

#define maxN 7003
#define dumm ('-')

typedef long maxn;
typedef std::string str;

maxn n, N, K, f[maxN][maxN], cnt[maxN], res;
str s;
std::vector <maxn> endpoint;


void Prepare() {
    std::cin >> n >> K >> s;
    str st;
    for(maxn i = 1; i < n; i++) {
        std::cin >> st;
        endpoint.push_back(s.size());
        s += dumm + st;
    }
    endpoint.push_back(s.size());
    s += dumm;
    //std::cout << s << '\n';
    N = s.size();
}


void Process() {
    for(maxn i = N - 1; i >= 0; i--) for(maxn j = N - 1; j >= 0; j--) {
        if (s[i] != s[j] || s[i] == dumm) continue;
        f[i][j] = f[i + 1][j + 1] + 1;
        //std::cout << i << ' ' << j << ' ' << ' ' << s[i] << ' ' << s[j] << ' ' << f[i][j] << '\n';
    }

    res = 0;
    for(maxn i = 0; i < N; i++) {
        if (s[i] == dumm) continue;
        std::fill(cnt, cnt + N + 2, 0);
        maxn j, MX = *std::upper_bound(endpoint.begin(), endpoint.end(), i) - i, mx;
        for(j = i + 1; j < N && s[j] != dumm; j++);
        for(j = j + 1, mx = 0; j < N; j++) {
            mx = std::min(MX, std::max(mx, f[i][j]));
            if (s[j] == dumm) ++cnt[0], --cnt[mx + 1]/*, std::cout << "cnt " << i << ' ' << mx << '\n'*/, mx = 0;
            if (mx == MX) j = *std::lower_bound(endpoint.begin(), endpoint.end(), j) - 1;
        }
        for(maxn len = 1; len <= MX; len++) {
            cnt[len] += cnt[len - 1];
            if (cnt[len] >= K - 1) res = std::max(res, len);
        }
    }

    std::cout << res;
}


int main() {
    freopen("tv.inp", "r", stdin);
    freopen("tv.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
