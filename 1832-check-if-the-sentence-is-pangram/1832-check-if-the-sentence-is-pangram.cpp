class Solution {
public:
    bool checkIfPangram(string sentence) {
       unordered_map<char,int> mp;
        
        for(auto x:sentence)
        {
            mp[x]++;
        }
        vector<int> v;
        for(auto x:mp)
        {
            v.push_back(x.first);
        }
        
        return v.size() == 26;
    }
};