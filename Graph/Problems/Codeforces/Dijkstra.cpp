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
typedef pair<long long int, int> pli;
const int N = 1e5+7;
const long long int INF = 1e18+7;
vector<int> parent(N,-1);
vector<pii> g[N];
vector<bool> visited(N,false);
vector<long long int> dist(N, INF);
void dijkstra(int source)
{
	priority_queue<pli, vector<pli>, greater<pli>>pq;
	dist[source] = 0;
	pq.push({dist[source], source});

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
				parent[v] = u;
				pq.push({dist[v], v});
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

    if(parent[n]==-1)
    {
    	cout << "-1\n";
    }
    else
    {
    	vector<int> path;
    	int curr = n;
    	while(curr!=-1)
    	{
    		path.push_back(curr);
    		curr = parent[curr];
    	}

    	reverse(path.begin(), path.end());
    	for(auto p:path)
    	{
    		cout << p << " ";
    	}
    }

 	return 0;
    
}
