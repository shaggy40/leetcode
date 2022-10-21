class Solution {
public:
    int dp[2001][2001];
    bool solve(vector<int> &stones,unordered_map<int, int>&mp,int i,int k)
    {
        
        if(k<=0)
            return false;
        
        if(mp.find(k+stones[i-1]) == mp.end())
            return false;
        else
            i=mp[k+stones[i-1]];
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        if(i==stones.size()-1)
            return true;
        
        return dp[i][k] = solve(stones,mp,i+1,k-1) || solve(stones,mp,i+1,k) || solve(stones,mp,i+1,k+1);
        
    }
    bool canCross(vector<int>& stones) {
        int i=1;
        int k = 1;
        memset(dp,-1,sizeof(dp));
        unordered_map<int,int> mp;
        
        for(int i=0;i<stones.size();i++)
        {
            mp[stones[i]] = i;
        }
        
        if(stones[1]!=1)return false;
        
        return solve(stones,mp,i,k);
    }
};