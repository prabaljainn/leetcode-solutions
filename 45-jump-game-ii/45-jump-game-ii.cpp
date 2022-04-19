class Solution
{
    public:

        vector<int> arr;
    int n;
    int dp[10010];
    int rec(int level)	//returns the min num of jumps to reach n
    {
        if (level >= n-1)
            return 0;

        if (dp[level] != -1)
            return dp[level];

        int ans = 1e9;

        for (int i = level+1; i <= level + arr[level]; i++)
        {
            ans = min(ans, 1 + rec(i));
        }

        return dp[level] = ans;
    }

    int jump(vector<int> &nums)
    {

        n = nums.size();
        arr = nums;
        for (int i = 0; i < n + 1; i++)
            dp[i] = -1;
        return rec(0);
    }
};