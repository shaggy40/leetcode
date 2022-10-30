class Solution {
public:
    int solve(int m,int n,string s,string t,vector<vector<int>> &dp)
    {

        for(int i=0;i<=m;i++)dp[i][0] = 0;
        for(int j=0;j<=n;j++)dp[0][j] = 0;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
        
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        int lcs = solve(m,n,word1,word2,dp);
        
        return m+n-2*lcs;
    }
};