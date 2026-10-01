class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_set<char> collection;
        int maxLen = 0;
        for(int r = 0; r < s.size(); r++)
        {
            while(collection.contains(s[r]))
            {
                collection.erase(s[l]);
                l++;
            }
            collection.insert(s[r]);
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
