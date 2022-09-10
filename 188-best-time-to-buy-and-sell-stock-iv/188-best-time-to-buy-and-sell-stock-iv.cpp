class Solution
{
    public:

        /*
            level = day;
            choices = buy, sell, nothing 
            check -> you can only sell if you have buyed last time and vice versa
            put ==1  if  you buyed last time
            put==0 if you sold last time
           	// put 3 you did nothing
            profit is the profit at that state
            transactions is transactions left
        */
        vector<int> arr;
    int dp[1002][3][109];
    bool flag[1002][3][109];
    int n;

    int rec(int level, int put, int transactions)
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
            ans = max(ans,( rec(level + 1, 1, transactions)- arr[level]));
        }
        else if (put == 1)
        {
            ans = max(ans, (rec(level + 1, 0, transactions - 1 )+ arr[level]));
        }

        flag[level][put][transactions] = true;

        return dp[level][put][transactions] = ans;
    }
    int maxProfit(int k, vector<int> &prices)
    {
        arr = prices;
        n = prices.size();
        memset(flag, false, sizeof(flag));
        cout << rec(0, 0, k);
        return rec(0, 0, k);
    }
};