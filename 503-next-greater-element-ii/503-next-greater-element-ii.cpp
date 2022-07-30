class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> ans(n, -1);
            stack<int> s;
            for (int i = 0; i < n; i++)
            {
                while (!s.empty() and(nums[i] > nums[s.top()]))
                {
                    int idx = s.top();
                    s.pop();
                    ans[idx] = nums[i];
                }
                s.push(i);
            }
            for (int i = 0; i < n; i++)
            {
                while (!s.empty() and(nums[i] > nums[s.top()]))
                {
                    int idx = s.top();
                    s.pop();
                    ans[idx] = nums[i];
                }
                s.push(i);
            }
            return ans;
        }
};