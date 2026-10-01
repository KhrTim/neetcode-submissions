class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int leftMax = height[l], rightMax = height[r];
        int totalWater = 0;
        while(l < r)
        {
            if(leftMax < rightMax)
            {
                l++;
                totalWater += max(0, leftMax - height[l]);
                leftMax = max(leftMax, height[l]);
            }
            else
            {
                r--;
                totalWater += max(0, rightMax - height[r]);
                rightMax = max(rightMax, height[r]);
            }
        }
        return totalWater;
    }
};
