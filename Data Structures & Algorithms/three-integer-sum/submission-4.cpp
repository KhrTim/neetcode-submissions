class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> triplets;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > 0)
                break;
            if(i > 0 and nums[i] == nums[i-1])
                continue;
            if(i + 1 < nums.size())
            {
                int l = i + 1, r = nums.size() - 1;
                while(l < r)
                {
                    int sum = nums[l] + nums[r] + nums[i];
                    if(sum < 0)
                    {
                        l++;
                    }
                    else if(sum > 0)
                    {
                        r--;
                    }
                    else
                    {
                        triplets.push_back({nums[l], nums[r], nums[i]});
                        l++;
                        r--;
                        while(l < r and nums[l] == nums[l-1])
                            l++;
                        while(l < r and nums[r] == nums[r+1])
                            r--;
                    }
                }
            }
            
        }
        return triplets;
    }
};
