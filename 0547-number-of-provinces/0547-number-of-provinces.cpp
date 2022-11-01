class Solution
{
    public:
        int n;
    void dfs(int node, vector<bool> &vis, vector<vector< int>> &arr)
    {
        vis[node] = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[node][i] and!vis[i])
            {
                dfs(i, vis, arr);
            }
        }
    }
    int findCircleNum(vector<vector < int>> &arr)
    {
        n = arr.size();
        if (n == 0)
            return 0;

        vector<bool> vis(n, false);

        int si = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                si++;
                dfs(i, vis, arr);
            }
        }
        return si;
    }
};