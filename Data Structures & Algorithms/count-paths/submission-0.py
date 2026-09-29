class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # 1. Create independent rows using list comprehension
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        # 2. Base case: There is 1 way to be at the start
        dp[1][1] = 1

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # Skip the starting square so we don't overwrite the base case
                if i == 1 and j == 1:
                    continue
                # Path = Ways from above + Ways from the left
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        
        return dp[m][n]