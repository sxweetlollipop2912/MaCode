// not done
//F. Fruit Sequences
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define maxN 500002
#define L first
#define R second
#define len(i) (in[i].R - in[i].L + 1)

typedef long maxn;
typedef long long maxr;
typedef std::pair <maxn, maxn> in_t;

maxn n;
maxr f[maxN];
std::string a;
std::vector <in_t> in;
std::vector <maxn> dq;


void Prepare() {
    std::cin >> n >> a;
}


void Process() {
    for(maxn l = 0, r = 0; r < n; r++) {
        if (a[r] == 0) 
            l = r + 1;
        else if (r + 1 == n || a[r + 1] == 0)
            in.push_back(in_t(l + 1, r + 1));
    }
    
    for(maxn ii = 0; ii < in.size(); ii++) {
        while (!dq.empty() && len(dq.back()) <= len(ii)) dq.pop_back();
        maxn ll = dq.empty()? 1 : 
        for(maxn i = in[ii].L; i <= in[ii].R; i++) {

        }
    }
}