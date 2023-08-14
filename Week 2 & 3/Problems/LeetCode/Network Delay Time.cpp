class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int N=105;
        vector<pair<int,int>> g[N];
        vector<int> dist(N,1e9+7);
        vector<int> parent(N,-1);
        vector<bool> visited(N, false);

        for(auto e:times)
        {
            g[e[0]].push_back({e[1],e[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        dist[k] = 0;
        parent[k] = 0;
        pq.push({dist[k],k});

        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            visited[u] = true;

            for(pair<int,int> vpair:g[u])
            {
                int v = vpair.first;
                int w = vpair.second;

                if(visited[v]) continue;

                if(dist[v] > dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                    parent[v] = u;
                    pq.push({dist[v],v});
                }
            }
        }

        bool poss = true;
        int maxx = 0;
        for(int i=1;i<=n;i++)
        {
            if(parent[i]==-1)
            {
                poss = false;
            }
            maxx = max(maxx, dist[i]);
        }

        if(poss)
            return maxx;
        else
            return -1;
    }
};
