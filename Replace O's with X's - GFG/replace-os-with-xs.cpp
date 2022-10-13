//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int row,int col,vector<vector<char>> mat,vector<vector<int>> &vis,int delRow[],int delCol[])
    {
        int n = mat.size();
        int m = mat[0].size();
        
        vis[row][col] = 1;
        
        for(int i=0;i<4;i++)
        {
            int nRow = row+delRow[i];
            int nCol = col+delCol[i];
            
            if(nRow >=0 && nRow < n && nCol >= 0 && nCol < m  && !vis[nRow][nCol] 
            && mat[nRow][nCol] == 'O')
            {
                dfs(nRow,nCol,mat,vis,delRow,delCol);
            }
        }
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int> (m,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,1,0,-1};

        for(int j=0;j<m;j++)
        {
            
            //first row
            if(!vis[0][j] && mat[0][j] == 'O')
            dfs(0,j,mat,vis,delRow,delCol);
            
            //last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O')
            dfs(n-1,j,mat,vis,delRow,delCol);
            
        }
        
        for(int i=0;i<n;i++)
        
        {
            //first column
            if(!vis[i][0] && mat[i][0] == 'O')
            dfs(i,0,mat,vis,delRow,delCol);
            
            //last column
            if(!vis[i][m-1] && mat[i][m-1] == 'O')
            dfs(i,m-1,mat,vis,delRow,delCol);
            
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && mat[i][j] == 'O')
                mat[i][j] = 'X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends