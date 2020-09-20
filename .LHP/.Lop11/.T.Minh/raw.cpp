//By momo
#include <cstdio>
#include <algorithm>
#define N 1000
#define INF 999999999
using namespace std;

int n, w[N][N], ax[N], ay[N];
int vx[N], vy[N], mch[N];
bool dfs(int x){
	vx[x] = 1;
	for(int y = 0; y < n; y++){
		int t = ax[x] + ay[y] - w[x][y];
		if(!vy[y] && t == 0){
			vy[y] = 1;
			if(mch[y] < 0 || dfs(mch[y]))
				return mch[y] = x, 1;
		}
	}
	return 0;
}

void KM(){
	fill(mch, mch + n, -1);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			ax[i] = max(ax[i], w[i][j]);
	for(int i = 0; i < n; i++){
		while(!dfs(i)){
			int d = INF;
			for(int j = 0; j < n; j++) if(!vy[j])
				for(int k = 0; k < n; k++) if(vx[k])
					d = min(d, ax[k] + ay[j] - w[k][j]);
			for(int j = 0; j < n; j++) if(vx[j]) ax[j] -= d, vx[j] = 0;
			for(int j = 0; j < n; j++) if(vy[j]) ay[j] += d, vy[j] = 0;
		}
	}
}

int main (){
	int ans = 0; scanf("%d", &n);
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
		scanf("%d", &w[i][j]), ans += w[i][j];
	KM(); for(int i = 0; i < n; i++) ans -= ax[i] + ay[i];
	printf("%lf\n", 1.0*clock()/CLOCKS_PER_SEC);
}
