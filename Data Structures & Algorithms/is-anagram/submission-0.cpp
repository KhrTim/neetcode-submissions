class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }
        char pos[256]{};
        
        for(int i =0; i<s.size(); i++)
        {
            pos[s[i]]++;
            pos[t[i]]--;
        }
        for(int i =0; i<256; i++)
        {
            if(pos[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
