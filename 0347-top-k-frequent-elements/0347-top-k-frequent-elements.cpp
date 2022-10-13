class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            unordered_map<int, int> m;
            vector<pair<int, int>> arrr;
            for (int x: nums)
                m[x]++;

            for (auto elem: m)
            {
                arrr.push_back(make_pair(elem.first, elem.second));
            }

            srand(time(0));
            int n = arrr.size();

            while (1)
            {vector<pair<int, int>> arr= arrr;
                int idx = (int) rand() % n;
                swap(arr[idx], arr[n - 1]);

                int pivotIdx = 0;
                for (int i = 0; i < n - 1; i++)
                {
                    if (arr[i].second < arr[n - 1].second)

                        swap(arr[pivotIdx++], arr[i]);
                }
                if (pivotIdx == n-k)
                {
                    vector<int> ans;
                    for (int i = pivotIdx; i < n; i++)
                    {
                        ans.push_back(arr[i].first);
                    }
                    return ans;
                }
            }
        }
};