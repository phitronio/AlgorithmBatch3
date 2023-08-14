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
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
	visited[u] = true;
	for(int v: adj[u])
	{
		if(visited[v]) continue;
		dfs(v);
	}
}

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(int v: adj[u])
		{
			if(visited[v] == true) continue;
			q.push(v);
			visited[v] = true;
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
    	int u,v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    int cc = 0;

    for(int i=1;i<=n;i++)
    {
    	if(visited[i]) continue;
    	bfs(i);
    	cc++;
    }

    cout << "Number of connected components: " << cc << endl;
    

	  return 0;
    
}
