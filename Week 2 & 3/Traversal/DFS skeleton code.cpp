#include<bits/stdc++.h>
using namespace std;
void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
	// section 1: actions just after entering a node u
	visited[u] = true;
	cout << "Visiting node: " << u << endl;

	for(int v: adj[u])
	{
		// section 2: actions before entering any child node v
		if(visited[v] == true) continue;
		dfs(v);
		// section 3: actions after exiting any child node v
	}
	// section 4: actions just before exiting a node u
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


    dfs(1);

 	return 0;
    
}
