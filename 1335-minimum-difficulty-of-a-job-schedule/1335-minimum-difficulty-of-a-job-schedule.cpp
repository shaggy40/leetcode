class Solution {
public:
    int dp[301][11];
    int solve(vector<int> &jd,int d,int i,int n)
    {
        if(d ==1)
        {
            return *max_element(begin(jd)+i,end(jd));
        }
        
        if(dp[i][d] != -1)
            return dp[i][d];
        
        int maxD = INT_MIN;
        int result = INT_MAX;
        
        for(int j=i;j<=n-d;j++)
        {
            maxD = max(maxD,jd[j]);
            result = min(result,maxD+solve(jd,d-1,j+1,n));
        }
        
        return dp[i][d] = result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        memset(dp,-1,sizeof(dp));
        
        if(n<d)
            return -1;
        
        return solve(jobDifficulty,d,0,n);
    }
};