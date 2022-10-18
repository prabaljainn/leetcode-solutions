class Solution
{
    public:
        int k;

    bool check(int mid, vector<int> &arr, int k)
    {
        int val = 1;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > mid)
                return false;
            if (sum + arr[i] > mid)
            {
                val++;
                sum = arr[i];
            }
            else
                sum += arr[i];
        }
        if (sum > mid)
            val++;
        return val <= k;
    }
    int splitArray(vector<int> &nums, int k)
    {

        int lo = 0;
        int hi = 0;
        for (int x: nums)
            hi = hi += x;

        int ans = hi;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, nums, k))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        return ans;
    }
};