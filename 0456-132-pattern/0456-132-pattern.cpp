class Solution
{
    public:
        vector<int> PGelement(vector<int> &nums)
        {
            vector<int> ans(nums.size(), -1);

            stack<int> s;
            for (int i = 0; i < nums.size(); i++)
            {
                while (!s.empty() and(nums[s.top()] <= nums[i]))
                    s.pop();

                if (!s.empty())
                {
                    ans[i] = s.top();
                }

                s.push(i);
            }
            return ans;
        }

    bool find132pattern(vector<int> &nums)
    {
        vector<int> minsofar(nums.size());
        minsofar[0] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[minsofar[i - 1]])
                minsofar[i] = i;
            else if (nums[i] >= nums[minsofar[i - 1]])
                minsofar[i] = minsofar[i-1];
        }
        vector<int> PG = PGelement(nums);
        for(int x: PG)
            cout<<x<<" ";
        cout<<endl;
        for(int x: minsofar)
            cout<<x<<" ";
        cout<<endl;
        

        for (int i = 0; i < nums.size(); i++)
        {
            int prev_gre_index = PG[i];
            if (prev_gre_index != -1)
            {
                int min_prev_greator = minsofar[prev_gre_index];

                if (min_prev_greator < prev_gre_index and nums[i]> nums[min_prev_greator])
                    {cout<<i<<endl;
                    return true;}
            }
        }

        return false;
    }
};