//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size();
	    int n = grid[0].size();
	    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
	    queue<pair<pair<int,int>,int>> q;
	   vector<vector<int>> vis(m,vector<int>(n,0));
	   vector<vector<int>> dist(m,vector<int>(n,0));
	    
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(grid[i][j] == 1)
	            {
	            q.push({{i,j},0});
	            vis[i][j] = 1;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        
	        dist[row][col] = steps;
	        
	        for(auto it:dir)
	        {
	            int newRow = row+it.first;
	            int newCol = col+it.second;
	            
	            if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && !vis[newRow][newCol] && grid[newRow][newCol] == 0)
	            {
	                vis[newRow][newCol] = 1;
	                q.push({{newRow,newCol},steps+1});
	            }
	        }
	    }
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends