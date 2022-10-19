#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>> adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
         priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
         int mod = 1e9+7;
          vector<ll> ways(n,0),dis(n,LONG_MAX);
         dis[0] = 0;
         ways[0] = 1;
         pq.push({0,0});
         while(!pq.empty())
         {
             ll node = pq.top().second;
             ll dist = pq.top().first;
             
             pq.pop();
             
             for(auto it:adj[node])
             {
                 ll v = it.first;
                 ll eWt = it.second;
                 
                 if(dist+eWt < dis[v])
                 {
                     dis[v] = dist+eWt;
                     pq.push({dis[v],v});
                     ways[v] = ways[node];
                 }
                 else if(dist+eWt == dis[v])
                 {
                      ways[v]=(ways[v]+ways[node])%mod;
                 }
             }
         }
         return ways[n-1]%mod;
    }
};