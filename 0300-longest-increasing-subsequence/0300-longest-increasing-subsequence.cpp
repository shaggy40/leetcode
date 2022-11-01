class Solution {
    // Memoisation solution
    int recursion(vector < int > & nums, int n, int ind, int prevInd, vector < vector < int >> & dp) {
        if (ind == n) return 0;

        if (dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];

        int take = 0, notTake = 0;

        notTake = recursion(nums, n, ind + 1, prevInd, dp);

        if (prevInd == -1 || nums[ind] > nums[prevInd])
            take = 1 + recursion(nums, n, ind + 1, ind, dp);

        return dp[ind][prevInd + 1] = max(notTake, take);
    }
public:
    int lengthOfLIS(vector < int > & nums) {
        int n = nums.size();
        vector < vector < int >> dp(n, vector < int > (n + 1, -1));
        return recursion(nums, n, 0, -1, dp);
    }
};