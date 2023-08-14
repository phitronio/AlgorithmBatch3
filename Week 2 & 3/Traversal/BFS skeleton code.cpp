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

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		cout << "Visiting node: " << u << endl;
    //Section 1: Processing a node just after popping from the queue.

		for(int v: adj[u])
		{
      //Section 2: actions needed to take before pushing into the queue.
			if(visited[v] == true) continue;
			q.push(v);
			visited[v] = true;
      //Section 3: actions needed to take after pushing into the queue(not quite different from section 2)
		}
    //Section 4: Finally if anything needs to be done after pushing all the children into the queue
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

    bfs(1);

  	return 0;
    
}
