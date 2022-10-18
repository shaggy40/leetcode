//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        queue<pair<int,pair<int,int>>> q;
        
        int m = grid.size();
        int n = grid[0].size();;
        
        
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        
        dis[source.first][source.second] = 0;
        
        q.push({0,{source.first,source.second}});
        
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty())
        {
            int dist = q.front().first;
            
            int x = q.front().second.first;
            int y = q.front().second.second;
            
            q.pop();
            
            for(auto it: dir)
            {
                int nx = x+it.first;
                int ny = y+it.second;
                
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == 1)
                {
                    if(dist+1 < dis[nx][ny])
                    {
                        dis[nx][ny] = dist+1;
                        q.push({dist+1,{nx,ny}});
                    }
                }
            }
        }
        if(dis[destination.first][destination.second] == INT_MAX) return -1;
        return dis[destination.first][destination.second];
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends