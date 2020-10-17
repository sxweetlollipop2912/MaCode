// Done
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <set>

#define maxN 200002
#define maxA 99999999999999999
#define Sum(l, r) (sum[r] - sum[l - 1])

typedef long maxn;
typedef long long maxa;

maxn n;
maxa M, a[maxN], sum[maxN], f[maxN], fm[maxN];
std::deque <maxn> dq;
std::multiset <maxa> set;


bool Prepare() {
    std::cin >> n >> M;
    for (maxn i = 1; i <= n; i++) {
        std::cin >> a[i];
        if (a[i] > M) return 0;
    }

    sum[0] = 0, sum[1] = a[1];
    for (maxn i = 2; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    return 1;
}


void Process() {
    f[0] = fm[0] = 0;
    f[1] = fm[1] = a[1];
    dq.push_front(1); set.insert(fm[1]);

    for (maxn i = 2, j = 1; i <= n; i++) {
        while (Sum(j, i) > M) ++j;

        while (!dq.empty() && a[dq.front()] <= a[i]) {
            set.erase(set.find(fm[dq.front()]));
            dq.pop_front();
        }
        while (!dq.empty() && dq.back() < j) {
            set.erase(set.find(fm[dq.back()]));
            dq.pop_back();
        }
        if (!dq.empty() && fm[dq.back()] != a[dq.back()] + f[j - 1]) {
            set.erase(set.find(fm[dq.back()]));
            fm[dq.back()] = a[dq.back()] + f[j - 1];
            set.insert(fm[dq.back()]);
        }

        maxn jj = dq.empty()? j : dq.front() + 1;

        fm[i] = f[i] = a[i] + f[jj - 1];
        if (!set.empty()) f[i] = std::min(f[i], *set.begin());

        dq.push_front(i); set.insert(fm[i]);
    }

    std::cout << f[n];
}

int main() {
    freopen("main.inp", "r", stdin);
    //freopen("main.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    if (Prepare()) Process();
    else std::cout << "-1";
}