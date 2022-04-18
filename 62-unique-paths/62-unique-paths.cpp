class Solution
{
    public:
       	// at any point of time he can go right or down
        int dp[105][105];
    int m, n;
    int rec(int i, int j)
    {
       	// pruning 
        if (i >= m or j >= n)
            return 0;
       	// case
        if (i == m - 1 and j == n - 1)
            return 1;
        int ans = 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        
        ans += rec(i + 1, j);
        ans += rec(i, j + 1);

        return dp[i][j] = ans;
    }

    int uniquePaths(int M, int N)
    {
        m = M;
        n = N;

       	// manual memset
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
                dp[i][j] = -1;
        }

        return rec(0, 0);

    }
};