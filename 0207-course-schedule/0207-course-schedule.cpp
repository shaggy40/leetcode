class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        
        vector<int> adj[n];
        
        for(auto it:p)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        queue<int> q;
        vector<int> ans;
        vector<int> in(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            in[it]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(in[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it: adj[node])
            {
                in[it]--;
                if(in[it] == 0)
                    q.push(it);
            }
        }
        
        return ans.size() == n;
    }
};