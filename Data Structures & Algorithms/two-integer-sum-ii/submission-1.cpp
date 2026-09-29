class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0, R = numbers.size() - 1;

        while((numbers[L] + numbers[R]) != target)
        {
            if(numbers[R] + numbers[L] > target)
            {
                R--;
            }
            else
            {
                L++;
            }
        }
        return {L+1, R+1};
    }
};
