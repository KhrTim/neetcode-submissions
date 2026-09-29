class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> buff(nums.begin(), nums.end());
        int max_len = 0;
        for (auto i: buff)
        {
            if (i != INT_MIN and not buff.contains(i-1))
            {
                int len = 1;
                int curr = i;
                while(curr != INT_MAX and buff.contains(curr+1))
                {
                    curr++;
                    len++;
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};
