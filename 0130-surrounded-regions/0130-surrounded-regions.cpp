class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        if(row<0 || row>=m || col<0 || col>=n || board[row][col]!='O' || vis[row][col] == 1)
            return;
        
        vis[row][col] = 1;
        
        dfs(row,col+1,vis,board);
        dfs(row+1,col,vis,board);
        dfs(row-1,col,vis,board);
        dfs(row,col-1,vis,board);
    }
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        
        
        vector<vector<int>> vis(m,vector<int> (n,0));
        
        for(int j=0;j<n;j++)
        {
            if(!vis[0][j] && board[0][j] == 'O')
                dfs(0,j,vis,board);
            
            if(!vis[m-1][j] && board[m-1][j] =='O')
                dfs(m-1,j,vis,board);
        }
        
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0] && board[i][0] == 'O')
                dfs(i,0,vis,board);
            
            if(!vis[i][n-1] && board[i][n-1] =='O')
                dfs(i,n-1,vis,board);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};