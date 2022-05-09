class Solution
{
    public:
        int visited = 0;
    bool vis[1001];
    void dfs(int node,vector<vector < int>> &g)
    {
        if (vis[node] == true)
            return;
        if (vis[node] == false)
            visited++;
        vis[node] = true;
        for (int x: g[node])
        {
            dfs(x,g);
        }
    }

    bool canVisitAllRooms(vector<vector < int>> &rooms)
    {
        memset(vis, false, sizeof(vis));

        dfs(0, rooms);
        
        // cout<<visited;
        return visited == rooms.size() ;
    }
};