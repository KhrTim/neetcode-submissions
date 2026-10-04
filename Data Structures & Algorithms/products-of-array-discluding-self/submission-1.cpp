class Solution {

public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n,1);
        vector<int> post(n,1);
        for(int i=1; i<n; i++)
        {
            pref[i] = pref[i-1] * nums[i-1];
        }
        for(int i=n-2; i>=0; i--)
        {
            post[i] = post[i+1] * nums[i+1];
        }

        vector<int> ans(n);

        for(int i =0; i < nums.size();i++)
        {
            ans[i] = pref[i] * post[i];
        }
        return ans;

    }
};
