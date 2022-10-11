class Solution {
public:
    void dfs(int oldColor,int i,int j,vector<vector<int>>& image,int color)
    {
        int m = image.size();
        int n = image[0].size();
        if(i<0 || j<0 || i>=m || j>=n ||image[i][j] == color || image[i][j]!=oldColor)
            return;
        
        
        image[i][j] = color;
        dfs(oldColor,i+1,j,image,color);
        dfs(oldColor,i-1,j,image,color);
        dfs(oldColor,i,j+1,image,color);
        dfs(oldColor,i,j-1,image,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        dfs(oldColor,sr,sc,image,color);
        return image;
    }
};