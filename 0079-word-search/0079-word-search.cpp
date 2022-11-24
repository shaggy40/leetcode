class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>> &board,string word,int count)
    {
        
        if(word.size() == count)return true;
        
        if(i<0 || i>= board.size() || j<0 || j>=board[0].size() || board[i][j] != word[count])
            return false;
        
        
        char temp = board[i][j];
        board[i][j] = ' ';
        
        bool ans = dfs(i+1,j,board,word,count+1)||
                   dfs(i-1,j,board,word,count+1)||
                   dfs(i,j+1,board,word,count+1)||
                   dfs(i,j-1,board,word,count+1);
            
        board[i][j] = temp;
        
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0] && dfs(i,j,board,word,0))
                    return true;
            }
        }
        return false;
    }
};