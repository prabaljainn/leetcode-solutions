class Solution
{
    public:
        vector<string> findRelativeRanks(vector<int> &score)
        {
            priority_queue<pair<int, int>> pq;
            int n = score.size();
            for (int i = 0; i < n; i++)
            {
                pq.push(make_pair(score[i], i));
            }
            vector<string> ans(n);
            for (int i = 0; i < n; i++)
            {
                auto x = pq.top();
                pq.pop();

                if (i == 0)
                {
                    ans[x.second] = "Gold Medal";
                }
                else if (i == 1)
                {
                    ans[x.second] = "Silver Medal";
                }
                else if (i == 2)
                {
                    ans[x.second] = "Bronze Medal";
                }
                else{
                    ans[x.second] = to_string(i+1);
                }
            }
            return ans;
        }
};