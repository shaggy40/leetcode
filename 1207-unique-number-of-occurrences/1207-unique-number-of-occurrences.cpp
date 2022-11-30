class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        
        vector<int> ans;
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        
        sort(ans.begin(),ans.end());
        
        int n1 = ans.size();
        
        for(int i=0;i<n1-1;i++)
        {
            if(ans[i] == ans[i+1])
                return false;
        }
        
        return true;
    }
};