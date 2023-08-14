#include<bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 1e5+7;
vector<int> g[N];
vector<bool> visited(N,false);
int level[N];
vector<int> parent(N,-1);

void bfs(int source)
{
	queue<int> q;
	q.push(source);
	level[source] = 0;
	visited[source] = true;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(int v:g[u])
		{
			if(visited[v]) continue;

			q.push(v);
			visited[v] = true;
			level[v] = level[u] + 1;
			parent[v] = u;
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
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    bfs(1);

    if(level[n]!=0)
    {
    	cout << level[n]+1 << endl;
    	vector<int> path;
    	int curr = n;
    	while(curr!=-1)
    	{
    		path.push_back(curr);
    		curr = parent[curr];
    	}
    	reverse(path.begin(), path.end());
    	for(int i:path)
    	{
    		cout << i << " ";
    	}
    }
    else
    	cout << "IMPOSSIBLE\n";
    

 	return 0;
    
}
