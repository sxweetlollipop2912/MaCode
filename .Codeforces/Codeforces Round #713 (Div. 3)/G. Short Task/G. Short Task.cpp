// G. Short Task
// AC
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define maxA 10000002

typedef long long maxa;

const maxa A = 1e7;

maxa Test, lp[maxA], sum[maxA], res[maxA];
std::vector <maxa> pr;


void Prepare() {
    std::cin >> Test;
}


void Era() {
    pr.clear(); lp[0] = lp[1] = 1; 
    sum[1] = 1; res[1] = 1;
    
    for(maxa i = 2; i <= A; i++) {
        if (!lp[i]) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(maxa j = 0; j < pr.size() && pr[j] <= lp[i] && (i * pr[j]) <= A; j++) {
            lp[i * pr[j]] = pr[j];
        }
        maxa cnt = 0, x = 1, sx = 1;
        for(maxa j = i; j % lp[i] == 0; j /= lp[i]) ++cnt, x *= lp[i], sx += x;

        sum[i] = sx * sum[i / x];
        if (sum[i] <= A && res[sum[i]] == 0) res[sum[i]] = i;
    }
}


void Process() {
    Era();

    while (Test--) {
        maxa c; std::cin >> c;
        if (res[c] == 0) std::cout << "-1\n";
        else std::cout << res[c] << '\n';
    }
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}