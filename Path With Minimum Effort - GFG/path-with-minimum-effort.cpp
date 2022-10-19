//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        
        //{diff,{row,col}}
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
        
        dis[0][0] = 0;
        pq.push({0,{0,0}});
        
        
        while(!pq.empty())
        {
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            
            pq.pop();
            
            if(x == m-1 && y == n-1)return diff;
            for(auto it:dir)
            {
                int nx = x+it.first;
                int ny = y+it.second;
                
                if(nx>=0 && nx<m && ny>=0 && ny<n )
                {
                    int newE = max(abs(heights[x][y]-heights[nx][ny]),diff);
                    if(newE < dis[nx][ny])
                    {
                        dis[nx][ny] = newE;
                        pq.push({newE,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends