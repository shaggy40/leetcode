class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<int> &pathV, vector<int> adj[])
    {
        vis[node]= 1;
        pathV[node] = 1;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathV,adj) == true)
                    return true;
            }
            else if(vis[it] == 1 && pathV[it] == 1)
                return true;
        }
        pathV[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        
        vector<int> adj[n];
        
        for(auto it:p)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> vis(n,0);
        vector<int> pathV(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,pathV,adj) == true)
                    return false;
            }
        }
        return true;
    }
};