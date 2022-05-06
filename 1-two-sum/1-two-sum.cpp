class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            unordered_map<int, int> m;
            int k;
            int a, b;
            for (int i = 0; i < nums.size(); i++)
            {
                k = target - nums[i];
                if (m.find(k) != m.end())
                {
                    a = m[k];
                    b = i;
                    break;
                }
                m[nums[i]] = i;
            }
            return {
                a,
                b
            };
        }
};