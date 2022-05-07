class Solution
{
    public:
        vector<vector < int>> g;
    vector<int> ind;
    vector<int> topo;

    void topo_sort(int n)
    {
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            topo.push_back(temp);
            for (int nodes: g[temp])
            {
                ind[nodes]--;
                if (ind[nodes] == 0)
                    q.push(nodes);
            }
        }
    }
    vector<int> findOrder(int n, vector<vector < int>> &pre)
    {
        g.resize(n);
        ind.resize(n);

        for (auto node: pre)
        {
            g[node[1]].push_back(node[0]);
            ind[node[0]]++;
        }

        topo_sort(n);
        if (n == topo.size())
            return topo;
        return {};
    }
};