class Solution
{
    public:

        bool validPath(int n, vector<vector < int>> &edges, int source, int destination)
        {
            vector<vector<int>>g(n+1);

           	// g.resize(edges.size());
            if (n == 1)
                return true;

            for (auto x: edges)
            {
                g[x[0]].push_back(x[1]);
                g[x[1]].push_back(x[0]);
            }

            bool vis[n];
            memset(vis, false, n);

            stack<int> s;
            s.push(source);

            while (!s.empty())
            {
                int elem = s.top();
                s.pop();
                vis[elem] = true;
                if (elem == destination)
                    return 1;

                for (auto x: g[elem])
                {

                    if (vis[x] == false)
                        s.push(x);
                }
            }
            return false;
        }
};