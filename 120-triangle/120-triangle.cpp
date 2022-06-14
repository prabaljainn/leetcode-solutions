class Solution
{
    public:
        int n;
    int dp[201][201];
    int rec(vector<vector < int>> &triangle, int level, int idx)
    {
       	//returns the best you can make on level taking index idx
        if (level == n)
            return 0;
        if (idx > level or idx < 0)
            return 1e9;
        if (dp[level][idx] != -1)
            return dp[level][idx];

        int ans = triangle[level][idx];

        ans = ans + min(rec(triangle, level + 1, idx), rec(triangle, level + 1, idx + 1));
        return dp[level][idx] = ans;
    }
    
    int minimumTotal(vector<vector < int>> &triangle)
    {
        memset(dp,-1, sizeof(dp));
        n = triangle.size();
        return rec(triangle, 0, 0);
    }
};


