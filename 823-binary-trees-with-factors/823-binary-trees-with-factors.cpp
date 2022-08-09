class Solution
{
    public:
        int mod = 1e9 + 7;
    vector<int> arr;
    int dp[1002];
    int n;
    long long rec(int level)
    {
        if (level == 0)
            return 1;

        if (dp[level] != -1)
            return dp[level];

        long long ans = 1;

        long long i = 0;
        long long j = level - 1;
        while (i <= j)
        {
            long long mul = (1LL *arr[i] *arr[j]);
            if (mul == arr[level])
            {
                if (i == j)
                    ans += (rec(i) *rec(i)) % mod;
                else
                    ans += 2 *(rec(i) *rec(j)) % mod;
                i++;
                j--;
            }
            else if (mul > arr[level])
                j--;
            else
                i++;
        }

        return dp[level] = (int)(ans % mod);
    }

    int numFactoredBinaryTrees(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        n = arr.size();
        this->arr = arr;
        memset(dp, -1, sizeof(dp));
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += rec(i);

        return sum % mod;
    }
};