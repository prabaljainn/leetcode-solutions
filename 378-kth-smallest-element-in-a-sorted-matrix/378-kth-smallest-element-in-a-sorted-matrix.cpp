class Solution
{
    public:
        int n;
    bool check(vector<vector < int>> &arr, int k, int mid)
    {
        int Row = n - 1;
        int Col = 0;
        int ans = 0;
        while (Row >= 0 and Col < n)	//Termination condition) 
        {
            if (arr[Row][Col] <= mid)
            {
                ans += (Row + 1);
                Col += 1;
            }
            else
            {
                Row -= 1;
            }
        }
        return ans >= k;
    }

    int kthSmallest(vector<vector < int>> &arr, int k)
    {
        n = arr.size();
        int lo = arr[0][0];
        int hi = arr[n - 1][n - 1];
        int ans = lo;
        while (hi >= lo)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(arr, k, mid))
            {
                hi = mid - 1;
                ans = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};