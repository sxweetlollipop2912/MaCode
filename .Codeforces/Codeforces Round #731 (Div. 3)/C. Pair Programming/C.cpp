// AC
#include <iostream>
#include <vector>

typedef int maxn;

maxn k, n1, n2;
std::vector <maxn> v1, v2;


void Prepare() {
    std::cin >> k >> n1 >> n2;
    v1.clear();
    v2.clear();

    for(maxn i = 0; i < n1; i++) {
        maxn x; std::cin >> x;
        v1.push_back(x);
    }
    for(maxn i = 0; i < n2; i++) {
        maxn x; std::cin >> x;
        v2.push_back(x);
    }
}


bool Process() {
    maxn max_line = k;
    std::vector <maxn> res;

    for(maxn i1 = 0, i2 = 0; i1 < n1 || i2 < n2;) {
        if (i1 < n1 && v1[i1] <= max_line) {
            if (!v1[i1]) ++max_line;
            res.push_back(v1[i1]);
            ++i1;
        }
        else if (i2 < n2 && v2[i2] <= max_line) {
            if (!v2[i2]) ++max_line;
            res.push_back(v2[i2]);
            ++i2;
        }
        else return false;
    }

    for(maxn i = 0; i < res.size(); i++) std::cout << res[i] << ' ';
    std::cout << '\n';
    return true;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Prepare();
        if (!Process()) std::cout << "-1\n";
    }
}