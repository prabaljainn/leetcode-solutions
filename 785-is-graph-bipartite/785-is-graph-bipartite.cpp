class Solution
{
    public:

        int color[109];	//0 if non vis 1 and 2
    int n;
   	// bool vis[109];

    bool flag = false;

    void dfs(int node, vector<vector < int>> &g, int clr)
    {
        color[node] = clr;

        for (int elem: g[node])
        {
            if (color[elem] == -1)
                dfs(elem, g, 1 - clr);
            else if (color[elem] == clr)
            {
                flag = true;
                break;
            }
        }
    }
    bool isBipartite(vector<vector < int>> &graph)
    {
        n = graph.size();
        for (int i = 0; i < n; i++)
            color[i] = -1;

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
                dfs(i, graph, 0);

        }
        return !flag;
    }
};