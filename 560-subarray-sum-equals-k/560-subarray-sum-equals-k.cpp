class Solution
{
    public:
        int subarraySum(vector<int> &arr, int k)
        {
            int pre[arr.size()];
            pre[0] = arr[0];
            for (int i = 1; i < arr.size(); i++)
            {
                pre[i] = arr[i] + pre[i - 1];
            }

            unordered_map<int, int> mp;
            mp[0] = 1;
            int ans = 0;
            for (int x: pre)
            {
                int val = x - k;
                ans += mp[val];
                mp[x]++;
            }

            return ans;
        }
};