class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        array<bool, 300> chars{false};
        int maxLen = 0;
        for(int r = 0; r < s.size(); r++)
        {
            while(chars[s[r]])
            {
                chars[s[l]] = false;
                l++;
            }
            chars[s[r]] = true;
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
