class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> v[])
    {
        vis[node] = 1;
        for(auto it:v[node])
        {
            if(!vis[it])
                dfs(it,vis,v);
            }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> v[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        } 
        vector<int> vis(n,0);
        int c=0;
        for(int i=0;i<n;i++)
        {
            
            if(!vis[i])
            {
                c++;
                dfs(i,vis,v);
            }
            
        }
        return c;
    }
};