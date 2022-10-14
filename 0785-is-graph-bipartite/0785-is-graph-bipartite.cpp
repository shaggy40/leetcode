class Solution {
public:
    bool dfs(int start, vector<int> &color,vector<vector<int>>& graph)
    {
        
        if(color[start] == -1)
            color[start] = 0;
        
        for(auto it:graph[start])
        {
            if(color[it] == -1){
                color[it] = !color[start];
            if(dfs(it,color,graph) == false)
                return false;
            }
                
            else if(color[it] == color[start])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(color[i] == -1)
            {
                if(dfs(i,color,graph) == false)
                    return false;
            }
        }
        return true;
    }
};