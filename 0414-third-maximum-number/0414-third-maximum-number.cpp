class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        
        set<int> s;
        for(int i = 0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        
        vector<int> ans;
        
        for(auto it:s)
        {
            ans.push_back(it);
        }
        
        sort(ans.begin(),ans.end());
        int n1  = ans.size();
        if(ans.size() < 3)
        return ans[n1-1];
        
        return ans[n1-3];
            
        }
};