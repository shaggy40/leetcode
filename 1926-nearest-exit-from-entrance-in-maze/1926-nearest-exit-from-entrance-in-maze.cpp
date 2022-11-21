class Solution {
public:
    bool isValid(int x,int y,vector<vector<char>>& maze, vector<vector<int>> &vis)
    {
        int m = maze.size();
        int n = maze[0].size();
        if(x>=0 && y>=0 && x<m && y<n && !vis[x][y] && maze[x][y] != '+')
            return true;
        else
            return false;
    }
    
    bool isEnd(int x,int y,vector<vector<char>>& maze)
    {
        int m = maze.size();
        int n = maze[0].size();
        
        if(x == 0 || y==0 || x==m-1 || y==n-1)
            return true;
        else
            return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        vis[entrance[0]][entrance[1]] = 1;
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        
        int level = 0;
        
        while(!q.empty())
        {
            int s = q.size();
            
            while(s--)
            {
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                for(auto it:dir)
                {
                  int nx = x+it.first;
                  int ny = y+it.second;
                    
                  if(isValid(nx,ny,maze,vis))
                  {
                      if(isEnd(nx,ny,maze))
                      return level+1;
                      else
                      {
                          vis[nx][ny] = 1;
                          q.push({nx,ny});
                      }
                  }
                }
            }
            level++;
        }
        return -1;
    }
};