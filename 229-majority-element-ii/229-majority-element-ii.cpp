class Solution
{
    public:
        vector<int> majorityElement(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> ans;
            int m1(-1e9+1), m2(-1e9+1), c1(0), c2(0);
            for (int x: nums)
            {
                if (m1 == x)
                {
                    c1++;
                }
                else if (m2 == x)
                {
                    c2++;
                }
                else if (c1 == 0)
                {
                    m1 = x;
                    c1 = 1;
                }
                else if (c2 == 0)
                {
                    m2 = x;
                    c2 = 1;
                }
                else
                {
                    c1 -= 1;
                    c2 -= 1;
                }
            }
            c1=c2=0;
            for(int x: nums){
                if(x==m1)
                    c1++;
                else if(x==m2)
                    c2++;
            }
            if(c1>(n/3))
                ans.push_back(m1);
            if(c2>(n/3))
                ans.push_back(m2);
            return ans;
        }
};