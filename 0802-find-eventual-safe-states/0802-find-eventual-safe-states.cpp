class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<int> &pathV,vector<vector<int>>& graph,vector<int> &check)
    {
        vis[node] = 1;
        pathV[node] = 1;
        
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathV,graph,check) == true)
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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
         vector<int> ans;
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> pathV(V,0);
        vector<int> check(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,pathV,graph,check);
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