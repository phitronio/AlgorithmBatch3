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
typedef pair<long long int,int> pli;
const int N = 1e5+7;
const long long int INF = 1e18+7;
vector<long long int> dist(N,INF);
vector<bool> visited(N,false);
vector<pii> g[N];

void dijkstra(int source)
{
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	dist[source] = 0;
	pq.push({dist[source],source});

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		if(visited[u]) continue;
		
		visited[u] = true;

		for(pii vpair: g[u])
		{
			int v = vpair.first;
			int w = vpair.second;

			if(dist[v] > dist[u]+w)
			{
				dist[v] = dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
}

// O(n + mlogn)

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init_code();
    
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
    	int u,v,w;
    	cin >> u >>v >> w;
    	g[u].push_back({v,w});
    }
    
    dijkstra(1);

    for(int i=1;i<=n;i++)
    {
    	cout << dist[i] << " ";
    }

 	return 0;
    
}
