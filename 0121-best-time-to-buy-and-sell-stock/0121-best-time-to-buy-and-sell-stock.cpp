class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minp = INT_MAX;
        int maxpro = INT_MIN;
        for(int i= 0 ;i<n;i++)
        {
            minp = min(minp,prices[i]);
            maxpro = max(maxpro,prices[i] - minp);
        }
        return maxpro;
    }
};