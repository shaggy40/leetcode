class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
    for(auto it:flights)
    {
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,pair<int,int>>> q;
    
    vector<int> dis (n,INT_MAX);
    
    q.push({0,{src,0}});
    while(!q.empty())
    {
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        
        
        if(stops > k) continue;
        for(auto it:adj[node])
        {
            int v = it.first;
            int newC = it.second;
            
            if(cost + newC < dis[v])
            {
                dis[v] = cost+newC;
                q.push({stops+1,{v,dis[v]}});
            }
        }
    }
    
    
    if(dis[dst] == INT_MAX)
    return -1;
    return dis[dst];
    }
};