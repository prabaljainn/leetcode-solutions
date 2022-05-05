class Solution
{
    public:
    int dx[4] = {1, 0, -1, 0};
    int n, m;
    int dy[4] = {0, 1, 0, -1};
    
    int color[302][302];
    int id = 1;
    bool check(int x, int y, vector<vector < char>> &arr)
    {
        if (x < n and x>=0 and y>=0 and y < m and arr[x][y] == '1' and color[x][y]==0)
            return true;
        
        return false;
    }
    void dfs(int x, int y, vector<vector < char>> &grid) {
        
        color[x][y]= id;
        for(int i=0; i<4; i++){
            if(check(x+dx[i], y+dy[i], grid))
                dfs(x+dx[i], y+dy[i], grid);
        }
        
    }
    
    int numIslands(vector<vector < char>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        
        memset(color, 0, sizeof(color));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (color[i][j] == 0 and grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    id++;
                }
            }
        }
        return id-1;
    }
};