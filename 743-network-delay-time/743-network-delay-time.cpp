class Solution
{
    public:
        int inf = 1e9;
    vector<vector<pair<int, int>>> g;
    int networkDelayTime(vector<vector < int>> &graph, int n, int k)
    {
        g.resize(n + 1);
        for (auto elem: graph)
        {
            g[elem[0]].push_back(make_pair(elem[1], elem[2]));
        }

        int dis[n + 1];
        bool vis[n + 1];
        for (int i = 1; i <= n; i++)
        {
            vis[i] = false;
            dis[i] = inf;
        }

        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, k));
        dis[k] = 0;
        while (!pq.empty())
        {
            pair<int, int> temp = pq.top();
            pq.pop();
            int node = temp.second;
            int distance = -temp.first;

            if (vis[node])
                continue;
            vis[node] = true;

            for (auto vec: g[node])
            {
                        int curr = vec.first;
                int duuri = vec.second;
                
                    if (dis[curr] > distance + duuri)
                    {
                        dis[curr] = distance + duuri;
                        pq.push(make_pair(-dis[curr], curr));
                    }
            
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, dis[i]);
        }
        if (ans == inf)
            return -1;
        return ans;
    }
};