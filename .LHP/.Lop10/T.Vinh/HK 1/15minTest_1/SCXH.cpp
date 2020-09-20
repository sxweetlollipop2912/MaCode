#include <iostream>
#include <fstream>

int m, n, a[1000], id[1000], num, old_num;
bool done[1000];

void Prepare() {
    std::cin >> n >> m;

    for(int i=0;i<n;i++) {
        std::cin >> a[i];
        id[a[i]]=i;
    }
}

bool check() {
    done[id[num]]=1;

    if ((old_num==-1) || (id[num]>=id[old_num])) return true;

    for(int i=id[old_num]-1;i>id[num];i--)
        if (done[i]==0) return false;
    return true;
}


int main() {
    freopen("SCXH.inp","r",stdin);
    freopen("SCXH.out","w",stdout);

    Prepare();

    for(int i=0;i<m;i++) {
        old_num = -1;
        std::fill(done,done+n,0);
        int j;
        for(j=0;j<n;j++) {
            std::cin >> num;
            if (!check()) break;
            old_num=num;
        }
        if (j==n) std::cout << "Yes" << '\n';
        else std::cout << "No" << '\n';
        while (++j<n) std::cin >> num;
    }
}
