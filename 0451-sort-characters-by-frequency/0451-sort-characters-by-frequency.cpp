class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        int n = s.size();
        
        for(auto it: s)
        {
            mp[it]++;
        }
        
        priority_queue<pair<int,char>> pq;
        
        
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        
        
        string s1 = "";
        while(!pq.empty())
        {
            char ch = pq.top().second;
            int freq = pq.top().first;
            pq.pop();
            for(int i=0;i<freq;i++)
            {
                s1+=ch;
            }
        }
        return s1;
    }
};