class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m)
            return 0;
        else
            return 1;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int oldcolor = image[sr][sc];
        
        if(image[sr][sc] == color)
            return image;
        
        int n = image.size();
        int m = image[0].size();
            
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            for(auto it : dir)
            {
                int i = node.first + it.first;
                int j = node.second + it.second;
                
                if(isValid(i,j,n,m) && image[i][j] == oldcolor)
                {
                    image[i][j] = color;
                    q.push({i,j});
                }
            }
        }
        return image;
        
    }
};