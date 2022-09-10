class Solution
{
    public:

        vector<int> arr;
    int dp[100100][3][2];
    bool flag[100100][3][2];
    int n;

    int rec(int level, int put, int transactions=1)
    {
       	// at level if you do put/pull with transactions transactions left how much max you can make;

        if (transactions == 0 or level == n)
        {
            return 0;
        }

        if (flag[level][put][transactions] == true)
            return dp[level][put][transactions];
        int ans = 0;;

        ans = max(ans, rec(level + 1, put, transactions));

        if (put == 0)
        {
           	// you can buy
            ans = max(ans, (rec(level + 1, 1, transactions) - arr[level]));
        }
        else if (put == 1)
        {
            ans = max(ans, (rec(level + 1, 0, transactions - 1) + arr[level]));
        }

        flag[level][put][transactions] = true;

        return dp[level][put][transactions] = ans;
    }
    int maxProfit(vector<int> &prices) {
        arr = prices;
        n = arr.size();
        
        return  rec(0, 0,1);
    }
};