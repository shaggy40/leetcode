class Solution {
public:
    int longestPalindrome(vector<string>& words) {
         int ans = 0 ;
        unordered_map<string, int> fre ;
        for(string &str : words)
        {
            reverse(str.begin(), str.end()) ;
            if(fre.find(str) != fre.end())
            {
                ans += 4 ;
                fre[str]-- ;
                if(fre[str] == 0) fre.erase(str) ;
            }
            else
            {
                reverse(str.begin(), str.end()) ;
                fre[str]++ ;
            }
        }
        for(pair<string,int> x : fre)
        {
            if(x.first[0] == x.first[1])
            {
                ans += 2 ;
                return ans ;
            }
        }
        return ans ;
    }
};