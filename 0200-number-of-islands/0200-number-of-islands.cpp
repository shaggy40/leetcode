class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m)
            return 0;
        else
            return 1;
    }
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& grid)
    {
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int,int>> q;
         q.push({row,col});
        while(!q.empty())
        {
            auto top = q.front();
            
            q.pop();
            
            for(auto it:dir)
            {
            
                     // if(abs(delRow)==abs(delCol)){continue;} //for ignoring diagonal 
                    int nRow = top.first + it.first;
                    int nCol = top.second + it.second;
if(isValid(nRow,nCol,n,m) && grid[nRow][nCol] == '1' && !vis[nRow][nCol])
{
    vis[nRow][nCol] = 1;
    q.push({nRow,nCol});
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