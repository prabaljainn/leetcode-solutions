class Solution
{
    public:
        int findJudge(int n, vector<vector < int>> &trust)
        {
            vector<int> out(n + 1, 0), in (n + 1, 0);

            for (auto elem: trust)
            {
                int a = elem[0];
                int b = elem[1]; in[b]++;
                out[a]++;
            }
            for (int i = 1; i <= n; i++) {
                if(in[i]==n-1 and out[i]==0)
                    return i;
            }

            return -1;
        }
};