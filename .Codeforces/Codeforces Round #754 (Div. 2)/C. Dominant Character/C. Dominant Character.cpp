// C. Dominant Character
// not done
#include <iostream>
#include <vector>
#include <algorithm>

#define maxN 1000001
#define B first
#define C second

typedef long maxn;
typedef std::pair <maxn, maxn> p_t;

std::string s;
maxn n, res;
p_t cnt[maxN];
std::vector <maxn> idx;


void Prepare() {
    std::cin >> n >> s;
}


bool less_p(const p_t& p1, const p_t& p2) {
    return p1.B < p2.B && p1.C < p2.C;
}


bool great_p(const p_t& p1, const p_t& p2) {
    return p1.B > p2.B && p1.C > p2.C;
}


// Find p_x < p
int binary_search(const p_t p) {
    if (idx.empty()) return n;

    maxn l = 0, r = idx.size() - 1;

    while (l < r) {
        maxn m = (l + r + 1) / 2;
        if (less_p(cnt[idx[m]], p)) l = m;
        else r = m - 1;
    }

    if (less_p(cnt[idx[l]], p)) return l;
    return n;
}


void Process() {
    idx.clear();
    res = n + 1;

    for(maxn i = 0; i < n; i++) {
        p_t p = i == 0? p_t(0, 0) : cnt[i - 1];

        if (s[i] == 'a') ++p.B, ++p.C;
        if (s[i] == 'b') --p.B;
        if (s[i] == 'c') --p.C;
        cnt[i] = p;

        maxn bs = binary_search(cnt[i]);
        if (i - bs + 1 >= 2) {
            res = std::min(res, i - bs + 1);
        }
        std::cout << i << ' ' << cnt[i].B << ' ' << cnt[i].C << ' ' << bs << '\n';
        if (!idx.empty()) std::cout << less_p(p, cnt[idx.back()]) << '\n';
        while (!idx.empty() && !less_p(cnt[idx.back()], p) ) idx.pop_back();
        idx.push_back(i);
        std::cout << idx.size() << '\n';
    }

    std::cout << res << '\n';
}


int main() {
    Prepare();
    Process();
}