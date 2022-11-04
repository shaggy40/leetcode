class Solution {
public:
    bool isVowel(char ch)
    {
        char currCh = tolower(ch); //lower all the characters to reduce checking for upppercase vowels
        if (currCh == 'a' || currCh == 'e' || currCh == 'i' || currCh == 'o' || currCh == 'u') return true;
        return false;
    }
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i<j)
        {
            if(isVowel(s[i]) && isVowel(s[j]))
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(!isVowel(s[i]))
            {
                i++;
            }
        
            else if(!isVowel(s[j]))
            {
                j--;
            }
        }
        return s;
    }
};