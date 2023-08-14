#include<bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 1e3+7;
const long long int INF = 1e18+7;
long long int g[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init_code();
    
    int n,m,q;

    cin >> n >> m >> q;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            g[i][j] = INF;
            if(i==j) g[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        long long int w;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v],w);
        g[v][u] = min(g[v][u],w);
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
        }
    }

    
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        if(g[a][b] == INF) cout << "-1\n";
        else cout << g[a][b] << endl;
    }
    

    return 0;
    
}
