//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int row,int col,vector<pair<int,int>> &vec,vector<vector<int>> &vis,vector<vector<int>>& grid,int row0,int col0)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        vis[row][col] = 1;
        vec.push_back({row-row0,col-col0});
        
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            
            for(auto it:dir)
            {
                int nrow = top.first+it.first;
                int ncol = top.second+it.second;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
                {
                    vec.push_back({nrow-row0,ncol-col0});
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<vector<pair<int,int>>> st;
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int,int>> vec;
                    bfs(i,j,vec,vis,grid,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends