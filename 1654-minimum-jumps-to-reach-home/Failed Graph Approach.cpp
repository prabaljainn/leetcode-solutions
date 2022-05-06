class Solution
{
    public:
        int inf = 1e9;

    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        unordered_map<int,int> m;
        for (int x: forbidden)
            m[x] = 1;
        int dis[6000];
        for (int i = 0; i < 6000; i++)
            dis[i] = inf;

        queue<pair<int, int>> q;	//node num and number of b's
        q.push({ 0,0 });	//at 0th pos and 0 b's used

        while (!q.empty())
        {
            pair<int, int> node = q.front();
            q.pop();
            int forward = node.first + a;
            int backward = node.first - b;
            int num_b = node.second;

            if (m[node.first])
                {continue;}

        m[node.first] = 1;

        if (node.first == x)
            return dis[node.first];

        if (forward <= 6000)
        {
            if (dis[forward] > dis[node.first] + 1)
            {
                dis[forward] = dis[node.first] + 1;
                q.push({forward,0});
            }
        }

        if (backward >= 0 and num_b == 0)
        {
            if (dis[backward] > dis[node.first] + 1)
            {
                dis[backward] = dis[node.first] + 1;
                q.push({backward,1});
            }
        }
    }
        return -1;
        }

};
