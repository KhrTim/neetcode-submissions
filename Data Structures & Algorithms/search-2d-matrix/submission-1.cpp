class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        int col = matrix[0].size();
        int row = matrix.size();
        while(l <= r)
        {
            int m = l + ((r-l) / 2);
            if(matrix[m][0] <= target and matrix[m][col-1] >= target)
            {
                int l1 = 0, r1 = col-1;
                while(l1 <= r1)
                {
                    int m1 = l1 + ((r1-l1)/2);
                    if(matrix[m][m1] < target)
                    {
                        l1 = m1 + 1;
                    }
                    else if(matrix[m][m1] > target)
                    {
                        r1 = m1 - 1;
                    }
                    else
                    {
                        return true;
                    }
                }
                return false;
            }
            else if(matrix[m][0] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return false;
    }
};
