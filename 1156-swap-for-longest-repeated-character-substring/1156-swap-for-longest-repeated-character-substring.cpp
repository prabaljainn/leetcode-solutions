class Solution
{
    public:
        int n;
    int solve(string s, char x)
    {
        // cout<<s<<" ";
        int ones = 0;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            
            if (s[i] == x)
            {
                arr[i] = 1;
                ones++;
            }
            else
            {
                arr[i] = 0;
            }
            // cout<<arr[i]<<" ";
        }
        
        int left[n];
        int right[n];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                left[i] = 0;
            }
            else
            {
                left[i] = 1;
                if (i)
                    left[i] += left[i - 1];
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] == 0)
            {
                right[i] = 0;
            }
            else
            {
                right[i] = 1;
                if (i != (n - 1))
                    right[i] += right[i + 1];
            }
        }
        int ans = 0;
        if(n==ones)
            return n;
        for (int i = 1; i < n - 1; i++)
        {
            int summ = left[i - 1] + right[i + 1];
            if (summ == ones)
            {
                ans = max(ans, summ);
            }
            else
            {
                ans = max(ans, summ + 1);
            }
        }
        return ans;
    }
    int maxRepOpt1(string text)
    {
        n = text.size();
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            ans = max(ans, solve(text, 'a' + i));
        }
        
        return ans;
    }
};