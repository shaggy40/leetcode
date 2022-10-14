//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]!=1 || vis[row][col] == 1)
        return;
        
        vis[row][col] = 1;
        
        dfs(row+1,col,vis,grid);
        dfs(row,col+1,vis,grid);
        dfs(row-1,col,vis,grid);
        dfs(row,col-1,vis,grid);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int j=0;j<n;j++)
        {
            if(!vis[0][j] && grid[0][j] == 1)
            dfs(0,j,vis,grid);
            
            if(!vis[m-1][j] && grid[m-1][j] == 1)
            dfs(m-1,j,vis,grid);
        }
        
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0] && grid[i][0] == 1)
            dfs(i,0,vis,grid);
            
            if(!vis[i][n-1] && grid[i][n-1] == 1)
            dfs(i,n-1,vis,grid);
        }
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends