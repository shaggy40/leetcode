class Solution {
public:
    int solve(vector<int> &arr,vector<int> &dp,int ind)
{
    if(ind == 0)return arr[ind];
    
    if(ind<0) return 0;
    
    if(dp[ind] != -1)
        return dp[ind];
    
    int take = arr[ind] + solve(arr,dp,ind-2);
    int ntake = 0+solve(arr,dp,ind-1);
    
    return dp[ind] = max(take,ntake);
}
    int rob(vector<int>& nums) {
        
        vector<int> temp1,temp2;
    int n = nums.size();
    if(n==1)return nums[0];
    vector<int> dp(n+1,-1);
    for(int i=0;i<n;i++)
    {
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=(n-1))temp2.push_back(nums[i]);
    }
    int fp = solve(temp1,dp,temp1.size()-1);
     vector<int> dp1(n+1,-1);
    int sp = solve(temp2,dp1,temp2.size()-1);
    return max(fp,sp);
    }
};