class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> &nums)
        {
            int n = nums.size();
            stack<int> s;
            vector<int> ans(n, -1);
            for (int j = 0; j < 2; j++)
            {
                for (int i = 0; i < n; i++)
                {
                    while (!s.empty() and nums[s.top()] < nums[i])
                    {
                        int id = s.top();
                        s.pop();

                        ans[id] = nums[i];
                    }
                    s.push(i);
                }
            }
            return ans;
        }
};