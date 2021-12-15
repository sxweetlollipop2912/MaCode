#include <iostream>
#include <algorithm>

#define maxN 200001

typedef long maxn, maxa;

maxn n, cnt[maxN];
maxa a[maxN];


void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> a[i];
}


bool Process() {
    {
        maxn peak = 0;
        for(; peak < n - 1 && a[peak] < a[peak + 1]; peak++);
        for(maxn i = 1; peak >= 0; peak--, i++)
            cnt[peak] = i;
    }

    {
        maxn peak = n - 1;
        for(; peak > 0 && a[peak] < a[peak - 1]; peak--);
        for(maxn i = 1; peak < n; peak++, i++)
            cnt[peak] = i;
    }

    {
        bool p = 1;
        maxa cur = -1;

        for(maxn l = 0, r = n - 1; ; p = !p) {
            if (!cnt[l] || a[l] <= cur)
                return !(p ^ (cnt[r] % 2 != 0));
            if (!cnt[r] || a[r] <= cur)
                return !(p ^ (cnt[l] % 2 != 0));
            
            if (a[l] == a[r]) {
                return !(p ^ (cnt[l] % 2 != 0 || cnt[r] % 2 != 0));
            }
            else if (a[l] > a[r]) {
                if (cnt[l] % 2 != 0)
                    return p;
                
                cur = a[r];
                --r;
            }
            else if (a[l] < a[r]) {
                if (cnt[r] % 2 != 0)
                    return p;
                
                cur = a[l];
                ++l;
            }
        }
    }

    return true;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    if (Process()) std::cout << "Alice";
    else std::cout << "Bob";
}