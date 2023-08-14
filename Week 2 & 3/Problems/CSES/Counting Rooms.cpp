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
const int N = 1e3+10;
vector<string> g;
int visited[N][N];
int n,m;
vector<pii> direc = {{0,-1},{0,1},{-1,0},{1,0}};

bool isValid(int i, int j)
{
	return (i>=0 && i<n && j>=0 && j<m);
}

void dfs(int i, int j)
{
	if(!isValid(i,j))
		return;
	if(visited[i][j])
		return;
	if(g[i][j] == '#')
		return;

	visited[i][j] = true;

	for(auto d:direc)
	{
		dfs(i+d.first, j+d.second);
	}
}

int main()
{
    init_code();

    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
    	string x;
    	cin >> x;
    	g.push_back(x);
    }
    int ct = 0;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(g[i][j]=='#') continue;
    		if(visited[i][j]) continue;
    		dfs(i,j);
    		ct++;
    	}
    }

    cout << ct << endl;

 	return 0;
    
}
