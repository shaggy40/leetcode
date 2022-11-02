class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
         queue<pair<string,int>> q;
        q.push({start,0});
        
        unordered_set<string> st(bank.begin(),bank.end());
        st.erase(start);
        
        vector<char> available = {'A', 'C', 'G', 'T'};
        
        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == end)return steps;
            for(int i=0;i<word.size();i++)
            {
                char original = word[i];
                for(int j= 0;j<4;j++)
                {
                    char ch = available[j];
                    word[i] = ch;
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return -1;
    }
};