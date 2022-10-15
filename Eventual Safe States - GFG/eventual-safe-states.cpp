//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node,vector<int> &vis,vector<int> &pathV,vector<int> adj[],vector<int> &check)
    {
        vis[node] = 1;
        pathV[node] = 1;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathV,adj,check) == true)
                {
                    check[it] = 0;
                    return true;
                }
            }
            else if(vis[it] == 1 && pathV[it] == 1)
            {
                check[it] = 0;
                return true;
            }
            
        }
        
        check[node] = 1;
        pathV[node] = 0;
        
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V,0);
        vector<int> pathV(V,0);
        vector<int> check(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,pathV,adj,check);
            }
        }
        
        for(int i=0;i<V;i++)
        {
            if(check[i] == 1)
            ans.push_back(i);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends