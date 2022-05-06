class Solution
{
    public:
        int inf = 1e9;

    int networkDelayTime(vector<vector < int>> &g, int n, int k)
    {
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

            for (auto vec: g)
            {
                if (vec[0] == node)
                {
                    if (dis[vec[1]] > distance + vec[2])
                    {
                        dis[vec[1]] = distance + vec[2];
                        pq.push(make_pair(-dis[vec[1]], vec[1]));
                    }
                }
            }
        }
        int ans =0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dis[i]);
        }
        if(ans ==inf)
            return -1;
        return ans;
    }
};