class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        queue<pair<int,pair<int,int>>> q;
        
        int m = grid.size();
        int n = grid[0].size();
        
        pair<int,int> source = {0,0};
        pair<int,int> destination = {n-1,n-1};
        
         if(grid[0][0] == 1)return -1;
       
        
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        
        dis[0][0] = 1;
       
        q.push({1,{0,0}});
        
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
        
        while(!q.empty())
        {
            int dist = q.front().first;
            
            int x = q.front().second.first;
            int y = q.front().second.second;
            
            q.pop();
            
            if(x == m-1 & y == n-1)return dist;
            for(auto it: dir)
            {
                int nx = x+it.first;
                int ny = y+it.second;
                
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == 0 && dist+1 < dis[nx][ny])
                {
                   
                        dis[nx][ny] = dist+1;
                        q.push({dist+1,{nx,ny}});
                
                }
            }
        }
        return -1;
        
    }
};