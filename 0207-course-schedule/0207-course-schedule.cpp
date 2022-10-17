class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> topoSort;
        
        vector<int> inDegree(numCourses,0);
        
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj[i])
            {
                inDegree[it]++;
            }
        }
        
    queue<int> q;
        
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            topoSort.push_back(node);
            
            for(auto it:adj[node])
            {
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
        
        return numCourses == topoSort.size();
    }
};