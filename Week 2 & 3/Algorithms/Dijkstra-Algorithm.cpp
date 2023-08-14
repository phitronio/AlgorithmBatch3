#include<bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}
typedef pair<int,int> pii;
const int N = 1e3+7;
const int INF = 1e9+7;
vector<pii> g[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int source)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[source] = 0;
	pq.push({0,source});

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		visited[u] = true;

		for(pii vpair: g[u])
		{
			int v = vpair.first;
			int w = vpair.second;

			if(visited[v]) continue;
			
			if(dist[v] > dist[u]+w)
			{
				dist[v] = dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
}

int main()
{
    init_code();
    
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
    	int u,v,w;
    	cin >> u >> v >> w;
    	g[u].push_back({v,w});
    	g[v].push_back({u,w});
    }

    dijkstra(1);

    for(int i=1;i<=n;i++)
    {
    	cout << "Distance of node " << i;
    	cout << " : " << dist[i] << endl;
    }
 	return 0;
    
}
