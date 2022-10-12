class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
        int vis[m][n];
        queue<pair<int,int>> q;
        
        int fresh=0,cnt=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    vis[i][j] = 2;
                }
                else 
                    vis[i][j] = 0;
                if(grid[i][j] == 1)
                    fresh++;
            }
        }
        int time =-1;
        while(!q.empty())
        {
            int sz= q.size();
            while(sz--)
            {
                auto top = q.front();
                q.pop();
                for(auto it : dir)
                {
                    int nrow = top.first + it.first;
                    int ncol = top.second + it.second;
                    
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                    {
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 2;
                        cnt++;
                    }
                }
            }
            time++;
        }
        
        if(fresh!=cnt)return -1;
        if(time == -1)return 0;
        return time;
    }
};