class Solution {
public:
    pair<int,int> getMostFreq(const array<int, 26>& counts)
    {
        int max_freq = 0;
        int max_pos = 0;
        for(int i =0; i<counts.size(); i++)
        {
            if(counts[i] > max_freq)
            {
                max_freq = counts[i];
                max_pos = i;
            }
        }
        return {max_freq, max_pos};
    }

    int characterReplacement(string s, int k) {
        array<int, 26> counts{0};
        int l = 0;
        int maxLen = 0;
        for(int r = 0; r < s.size(); r++)
        {
            counts[s[r] - 'A'] += 1;
            while(r-l+1  - getMostFreq(counts).first > k)
            {
                counts[s[l] - 'A'] -= 1;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
