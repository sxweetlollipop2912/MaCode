// undone
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define maxN 2001
#define L first
#define R second
#define len(p) (p.R - p.L + 1)

typedef int maxn;
typedef std::string str;
typedef std::pair <maxn, maxn> p_t;

str X, Y, Z;
maxn n, nA, nB, nC, DP[maxN][maxN], res;
p_t Pax[maxN], Pay[maxN], Pbx[maxN], Pbz[maxN], Pcy[maxN], Pcz[maxN];
std::vector <maxn> Iax, Iay;


void Prepare() {
    std::cin >> n >> X >> Y >> Z;
}


void GetCommons(const str& X, const str& Y, p_t Px[], p_t Py[], maxn& cnt) {
    cnt = 0;

    for(maxn stX = 0; stX < n; stX++) {
        maxn left = -1;
        for(maxn iy = 0; iy < n; iy++) {
            maxn ix = stX + iy;

            if (X[ix] == Y[iy]) {
                if (left == -1) left = iy;
            }
            else {
                if (left == -1) continue;
                Px[cnt] = p_t(stX + left, ix - 1);
                Py[cnt] = p_t(left, iy - 1);
                ++cnt;
                left = -1;
            }
        }
    }

    for(maxn stY = 1; stY < n; stY++) {
        maxn left = -1;
        for(maxn ix = 0; ix < n; ix++) {
            maxn iy = stY + ix;

            if (X[ix] == Y[iy]) {
                if (left == -1) left = ix;
            }
            else {
                if (left == -1) continue;
                Px[cnt] = p_t(left, ix - 1);
                Py[cnt] = p_t(stY + left, iy - 1);
                ++cnt;
                left = -1;
            }
        }
    }
}


bool cmp_ax(const maxn x1, const maxn x2) {
    return Pax[x1].L < Pax[x2].L;
}
bool cmp_ay(const maxn x1, const maxn x2) {
    return Pay[x1].L < Pay[x2].L;
}


maxn BS(const std::vector <maxn>& idx, const p_t p[], const maxn val) {
    maxn l = 0, r = idx.size() - 1;

    while (l != r) {
        maxn m = (l + r + 1) / 2;
        if (p[idx[m]].L > val) r = m - 1;
        else l = m;
    }

    if (p[idx[l]].L <= val) return idx[l];
    return -1;
}


void Process() {
    GetCommons(X, Y, Pax, Pay, nA);
    GetCommons(X, Z, Pbx, Pbz, nB);
    GetCommons(Y, Z, Pcy, Pcz, nC);

    for(maxn i = 0; i < nA; i++) {
        Iax.push_back(i); Iay.push_back(i);
        
        DP[Pax[i].R][Pay[i].L] = len(Pax[i]);
    }
    std::sort(Iax.begin(), Iax.end(), cmp_ax);
    std::sort(Iay.begin(), Iay.end(), cmp_ay);

    for(maxn i = 0; i < n; i++) for(maxn j = n - 1; j >= 0; j--) {
        if (i != 0) 
            DP[i][j] = std::max(DP[i][j], DP[i - 1][j]);
        if (j != n - 1)
            DP[i][j] = std::max(DP[i][j], DP[i][j + 1]);
        
        maxn idxA_on_X = BS(Iax, Pax, i);
        maxn idxA_on_Y = BS(Iay, Pay, j);
        if (idxA_on_X == -1 || idxA_on_X != idxA_on_Y) continue;

        DP[i][j] = std::max(DP[i][j], std::min(Pax[idxA_on_X].R - i + 1, j - Pay[idxA_on_Y].L + 1));
    }

    res = 0;
    for(maxn ib = 0; ib < nB; ib++) for(maxn ic = 0; ic < nC; ic++) {
        p_t bz = Pbz[ib], bx = Pbx[ib];
        p_t cz = Pcz[ic], cy = Pcy[ic];

        if (cz.R - bz.L + 1 < 2) continue;
        maxn t = bz.R < cz.L ? len(bz) + len(cz) : cz.R - bz.L + 1;

        if (bx.L == 0 || cy.R == n - 1) {
            res = std::max(res, t);
        }
        else res = std::max(res, t + DP[bx.L - 1][cy.R + 1]);
    }

    /*std::cout << "Axy " << nA << '\n';
    for(maxn i = 0; i < nA; i++) std::cout << Pax[i].L << ' ' << Pax[i].R << ' ' << Pay[i].L << ' ' << Pay[i].R << '\n';

    std::cout << "Bxz " << nB << '\n';
    for(maxn i = 0; i < nB; i++) std::cout << Pbx[i].L << ' ' << Pbx[i].R << ' ' << Pbz[i].L << ' ' << Pbz[i].R << '\n';

    std::cout << "Cyz " << nC << '\n';
    for(maxn i = 0; i < nC; i++) std::cout << Pcy[i].L << ' ' << Pcy[i].R << ' ' << Pcz[i].L << ' ' << Pcz[i].R << '\n';
    */

    std::cout << res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}