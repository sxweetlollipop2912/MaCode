//Undone
//D. Bouncing Boomerangs
#include <iostream>
#include <algorithm>
#include <set>

#define maxN 100001
#define R first
#define C second

typedef long maxn;
typedef int maxa;
typedef std::pair <maxn, maxn> p_t;

maxn n, r[maxN], cnt[maxN];
maxa a[maxN];
std::set <p_t> res;


void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> a[i];
}


bool Process() {
    r[0] = 1;
    for(maxn i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        if (r[i] > n) return 0;
        maxn ii = i;

        if (a[i] == 1) {
            if (res.find(p_t(r[i], i + 1)) == res.end()) {
                if (cnt[r[i]] + 1 > 2) ++r[i];
                if (r[i] > n) return 0;
                res.insert(p_t(r[i], i + 1));
            }
            ++r[i], cnt[r[i]] = 0;
        }
        else if (a[i] == 2) {
            if (res.find(p_t(r[i], i + 1)) == res.end()) {
                if (cnt[r[i]] + 2 > 2) ++r[i], cnt[r[i]] = 2;
                if (r[i] > n) return 0;
                res.insert(p_t(r[i], i + 1));

                while (a[++ii] != 1);
                res.insert(p_t(r[ii], ii + 1));
            }
            else {
                if (cnt[r[i]] + 1 > 2) return 0;
                while (a[++ii] != 1);
                r[ii] = r[i];
                res.insert(p_t(r[ii], ii + 1));
                ++cnt[r[ii]];
            }
        }
        else {
            if (r[i] == n) return 0;

            if (res.find(p_t(r[i], i + 1)) == res.end()) {
                if (cnt[r[i]] + 2 > 2) ++r[i], cnt[r[i]] = 2;
                if (r[i] > n) return 0;
                res.insert(p_t(r[i], i + 1));

                while (!a[++ii]);
                res.insert(p_t(r[ii], ii + 1));
            }
            else {
                if (cnt[r[i]] + 1 > 2) return 0;
                while (!a[++ii]);
                res.insert(p_t(r[ii], ii + 1));
                ++cnt[r[ii]];
            }
            ++r[ii], cnt[r[ii]] = 1;
            res.insert(p_t(r[ii], ii + 1));
        }
    }

    std::cout << res.size() << '\n';
    for(auto p : res) {
        std::cout << p.R << ' ' << p.C << '\n';
    }
    return 1;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    if (!Process()) std::cout << "-1";
}