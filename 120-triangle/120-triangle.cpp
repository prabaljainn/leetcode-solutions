class Solution {
public:
    int n;
    bool vis[400][400];
    int dp[400][400];
    int rec(vector<vector<int>>& triangle, int level, int idx){ //returns the best you can make on level taking index i
        if(level==n)
            return 0;
        if(idx >level or idx<0)
            return 1e9;
        if(vis[level][idx]==true)
            return dp[level][idx];
        
        vis[level][idx] = true;
        
        int ans = triangle[level][idx];
        
        ans = ans+ min( rec(triangle, level+1, idx), rec(triangle, level+1, idx+1));
        return dp[level][idx] = ans;
        }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(vis, false, sizeof(vis));
        n = triangle.size();
        return rec(triangle, 0, 0);
        
    }
};