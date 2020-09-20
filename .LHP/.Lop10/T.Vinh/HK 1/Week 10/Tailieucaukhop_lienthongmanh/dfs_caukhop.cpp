#include <cstdio>
#include <algorithm>
using namespace std;
#define maxN 1001
int n,m,u,v;
int number[maxN],low[maxN],parent[maxN],dem;
bool a[maxN][maxN];

void readfile(){
	freopen("cut.inp","r",stdin);
    freopen("cut.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=0;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        a[u][v]=1;
		a[v][u]=1;
    }
}

void Visit(int u){//tìm kiếm chiều sâu bắt đầu từ u
    dem++; number[u]=dem;
    low[u]=n+1; //gán low[u] giá trị vô cực
    for(int v=1;v<=n;v++){//Xét các đỉnh v
        if(a[u][v]){ //v kề u
			a[v][u]=0; //Bỏ đi cung (v,u)
			if(parent[v]==0){ //v chưa thăm
				parent[v]=u;
				Visit(v); //Thăm v
				low[u]=min(low[u],low[v]);
			}
			else //v đã thăm, (u,v) là cung ngược
                low[u]=min(low[u],number[v]);
		}

    }
}
void solve(){
	dem=0;
	for(int u=1;u<=n;u++)
		parent[u]=0;
	for(int u=1;u<=n;u++)
		if(parent[u]==0) //Gặp một đỉnh chưa thăm
		{
			parent[u]=-1; //Cho u là một gốc cây DFS
			Visit(u); //Xây dựng cây DFS gốc u
		}
}

void printresult(){ //In kết quả
	int u,v;
	int nchildren[maxN]; //Tính nChildren[u] = Số nhánh con của nhánh DFS gốc u
	bool isArticulation[maxN]; //Xác định có phải là khớp không
	printf("Bridges: \n"); //Liệt kê các cầu
	for(int v=1;v<=n;v++)
	{
		u=parent[v];
		if (u!=-1&&low[v]>=number[v])
			printf("(%d,%d)\n",u,v);
	}
	printf("Articulations:\n"); //Liệt kê các khớp
	for(int v=1;v<=n;v++)
		nchildren[v]=0;
	//Tính số nhánh con của mỗi đỉnh thuộc đồ thị sau khi định chiều DFS
	for(int v=1;v<=n;v++)
	{
		u=parent[v];
		if (u!=-1) nchildren[u]++;
	}
	//Đồ thị vô hướng ban đầu có nhiều thành phần liên thông, tương ứng khi định chiều DFS
	//tạo ra đồ thị có hướng với nhiều cây DFS, mỗi cây DFS có một gốc
	//u là khớp nếu u là gốc cây DFS và u có ít nhất 2 nhánh con
	for(int u=1;u<=n;u++)
		isArticulation[u]=(parent[u]==-1 && nchildren[u]>=2);
	//u là khớp nếu u KHÔNG LÀ GỐC CÂY DFS và low[v]>=number[u]
	for(int v=1;v<=n;v++){
		u=parent[v];
		if (u!=-1 && parent[u]!=-1) //Xét các cung (u,v) với u không phải là gốc cây DFS
			if (low[v]>=number[u])
				isArticulation[u]=1; //đánh dấu đỉnh u là khớp
	}
	for(int u=1;u<=n;u++) //Liệt kê các khớp của đồ thị
		if (isArticulation[u]) printf("%d\n",u);
}


int main()
{
	readfile();
    solve();
	printresult();
    return 0;
}






