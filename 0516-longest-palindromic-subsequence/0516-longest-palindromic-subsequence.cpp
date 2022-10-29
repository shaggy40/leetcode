
class Solution {
public:
    int solve(int ind1,int ind2,string s,string t,vector<vector<int>> &dp)
{
    for(int i=0;i<=ind1;i++)
        dp[i][0] = 0;
    
    for(int j=0;j<=ind2;j++)
        dp[0][j] = 0;
    
    for(int i=1;i<=ind1;i++)
    {
        for(int j=1;j<=ind2;j++)
        {
            if(s[i-1] == t[j-1])
        dp[i][j] = 1+dp[i-1][j-1];
    else
    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
  return dp[ind1][ind2];
   }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
       string t = s;
        reverse(t.begin(),t.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(n,n,s,t,dp);
    }
};