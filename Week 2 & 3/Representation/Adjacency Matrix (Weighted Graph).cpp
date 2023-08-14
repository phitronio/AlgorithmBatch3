#include<bits/stdc++.h>
using namespace std;
void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 1e3+5;
int adj_mat[N][N];

int main()
{
    init_code();
    
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
    	int u,v,w;
    	cin >> u >> v >> w;
    	adj_mat[u][v] = w;
    	adj_mat[v][u] = w; // comment out the opposite direction in case of directed graph
    }

    cout << "Printing the adjacency matrix:\n";
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		cout << adj_mat[i][j] << " ";
    	}
    	cout << endl;
    }

 	return 0;
    
}
