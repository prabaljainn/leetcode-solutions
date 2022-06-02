class Solution
{
    public:
        int consecutiveNumbersSum(int n)
        {
            long long int x = 1;
            long long int ans = 0;
            while (1)
            {
                int val = n - ((x *(x - 1)) / 2);
                if (val <= 0)
                    break;
                if (val % x == 0)
                {
                    ans++;
                }
                x++;
            }
            return ans;
        }
};