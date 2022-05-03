class Solution
{
    public:
        int findUnsortedSubarray(vector<int> &nums)
        {
            vector<int> arr = nums;
            sort(nums.begin(), nums.end());

            int l = 0;
            int r = arr.size() - 1;
            while (l != nums.size() and arr[l] == nums[l])
                l++;
            while (r != 0 and arr[r] == nums[r])
                r--;
            if (r > l)
                return r - l + 1;
            else
                return 0;
        }
};