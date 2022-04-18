class Solution
{
    public:
        int n;
    vector<int> arr;
    int dp[100100];
    int rec(int level)
    {
       	// base case
        if (level == n)
            return 0;

       	// dp check
        if (dp[level] != -1)
            return dp[level];

       	// calculate
        int ans = 0;
        for (int i = level + 1; i < n; i++)
        {
            if (arr[i] > arr[level])
            {
                ans = max(rec(i) + 1, ans);
            }
        }
        return dp[level] =ans ;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        n = nums.size();
        for (int i = 0; i < n + 10; i++)
            dp[i] = -1;
        arr = nums;
        int ans = rec(0);

        for (int i = 1; i < n; i++)
        {
            ans = max(rec(i), ans);
        }
        return ans+1;
    }
};