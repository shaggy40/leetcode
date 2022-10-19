//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
         int mod = (int)(1e9+7);
         vector<int> dis(n,1e9),ways(n,0);
         dis[0] = 0;
         ways[0] = 1;
         pq.push({0,0});
         while(!pq.empty())
         {
             int node = pq.top().second;
             int dist = pq.top().first;
             
             pq.pop();
             
             for(auto it:adj[node])
             {
                 int v = it.first;
                 int eWt = it.second;
                 
                 if(dist+eWt < dis[v])
                 {
                     dis[v] = dist+eWt;
                     pq.push({dis[v],v});
                     ways[v] = ways[node];
                 }
                 else if(dist+eWt == dis[v])
                 {
                     ways[v]+=ways[node];
                 }
             }
         }
         return ways[n-1]%mod;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends