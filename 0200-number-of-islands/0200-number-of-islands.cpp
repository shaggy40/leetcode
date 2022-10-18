class Solution {
public:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty())
        {
           int x = q.front().first;
           int y = q.front().second;
            
          q.pop();
            
            for(auto it:dir)
            {
                int nrow = x+it.first;
                int ncol = y+it.second;
                
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};