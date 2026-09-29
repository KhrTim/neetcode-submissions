class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> matches;
        for(int i = 0; i < nums.size(); i++)
        {
            if(matches.contains(target - nums[i]))
            {
                return {matches[target - nums[i]], i};
            }
            matches[nums[i]] = i;
        }
        return {};
    }
};
