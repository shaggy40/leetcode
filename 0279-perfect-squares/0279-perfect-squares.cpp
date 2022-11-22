class Solution {
public:
    int solve(int i,int n,int sum,vector<int> &arr,vector<vector<int>> &dp)
    {
        
        if(sum == 0)
          return 0;
        
        if(i>=n || sum<0)
             return INT_MAX - 1000;
        
         if(dp[i][sum] != -1)
        {
            return dp[i][sum];
        }

        // at each ith element we have two options either include or exclude

        int mini = INT_MAX;

        // inclusion part

        if(arr[i] <= sum)
        {
            mini = min(mini, 1 + solve(i, n, sum - arr[i],arr,dp));
        }

        // exclusion part

        mini = min(mini, solve(i + 1, n, sum,arr,dp));

        // store the res in dp

        return dp[i][sum] = mini;
        
        
    }
    int numSquares(int sum) {
        vector<int> arr;
        for(int i=1;i*i<=sum;i++)
        {
           arr.push_back(i*i);
        }
        
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        
        return solve(0,n,sum,arr,dp);
    }
};