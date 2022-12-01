class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int left = 0, right = 0, cnt = 0;
        int n = s.length();
      
        for(auto &it : s)
        {
           
            int temp = it - 'a';

            if(it >= 'A' && it <= 'Z') temp = it - 'A';

            if(temp == 0 || temp == 4 || temp == 8 || temp == 14 || temp == 20)
            {

            if(cnt < n/2) left++;

            else right++;
            
            }

            cnt++;
        }

        return (right == left);
    }
};