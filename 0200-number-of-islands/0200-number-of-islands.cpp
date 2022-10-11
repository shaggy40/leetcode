class Solution {
public:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int,int>> q;
         q.push({row,col});
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            for(int delRow = -1;delRow<=1;delRow++)
            {
                for(int delCol=-1;delCol<=1;delCol++)
                {
                     if(abs(delRow)==abs(delCol)){continue;} //for ignoring diagonal 
                    int nRow = row+delRow;
                    int nCol = col+delCol;
if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && !vis[nRow][nCol])
{
    vis[nRow][nCol] = 1;
    q.push({nRow,nCol});
}
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt=0;
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
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