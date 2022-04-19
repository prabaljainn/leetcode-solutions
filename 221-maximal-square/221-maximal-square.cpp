class Solution
{
    public:
        int dp[305][305];
    vector<vector < char>> arr;
    int n, m;

    int rec(int i, int j)
    {
        if (i < 0 or j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (arr[i][j] == '1')
        {
            return dp[i][j] = min({ rec(i - 1, j - 1),
                rec(i - 1, j),
                rec(i, j - 1) }) + 1;
        }
        else

            return dp[i][j] = 0;
    }
    int maximalSquare(vector<vector < char>> &matrix)
    {
        n = matrix.size();
        m = matrix[0].size();
        arr = matrix;
        memset(dp, -1, sizeof(dp));
        int ans =0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                ans = max(rec(i, j),ans);
        }
        return ans*ans;
    }
};