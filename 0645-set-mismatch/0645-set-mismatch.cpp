class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        vector<int> freq(n,0);
        
        for(int i=0;i<n;i++)
        {
            freq[nums[i]-1]++;
        }
        int m=0,r=0;
        for(int i=1;i<=n;i++)
        {
            if(freq[i-1] == 0)
             m = i;
            if(freq[i-1] > 1)
            r=i;
        }
        
        ans.push_back(r);
        ans.push_back(m);
        return ans;
    }
};