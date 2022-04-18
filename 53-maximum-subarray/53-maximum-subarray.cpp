class Solution
{
    vector<int> arr;
    int dp[100100];
    bool vis[100100];
    public:
        int rec(int level)
        {
            if (level == 0)
                {
                return dp[level] = arr[0];}

           	//dp check 
            if (vis[level] == true)
                return dp[level];
            
            
            vis[level] = true;
            
            int ans = rec(level - 1) + arr[level];

            ans = max(ans, arr[level]);

            return dp[level] = ans;
        }
    int maxSubArray(vector<int> &nums)
    {
        arr = nums;
        int n = nums.size();
        memset(vis, false, sizeof(vis));
        int ans = -1e9;
        rec(n-1);
        for (int i = 0; i < n; i++)
        {
            ans = max(rec(i) ,ans);
            // cout<<dp[i]<<" ";
        }
        
        return ans;
    }
};