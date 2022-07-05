
class Solution {
public:
    int n, m;
    // vector<vector<int>> arr;
    // vector<vector<int>> dp;
    // int dp[201][201];
    int dx[4]{0,0,-1,1};
    int dy[4]{-1,1,0,0};
    bool check(int x, int y){
        if(x>=0 and x<n and y>=0 and y<m)
            return true;
        return false;
    }
    
    int rec(int x, int y, vector<vector<int>>& dp,vector<vector<int>>& arr) //returns the longest inc path starting at (x,y)
    {
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        int ans = 0;
        for(int i=0; i<4 ;i++){
            int xt = x+dx[i];
            int yt = y+dy[i];
            if(check(xt,yt) and arr[xt][yt] > arr[x][y] )
            {
                ans = max(ans, (rec(xt,yt,dp,arr)) );
                
            }
        }
        return dp[x][y]= (ans+1);
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        n = matrix.size();
        m = matrix[0].size();
        int ans =0;
        vector<vector<int>> dp = matrix;
                for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // cout<<rec(i,j)<<" ";
         dp[i][j] = -1;
            }
            // cout<<endl;
        }
        
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // cout<<rec(i,j)<<" ";
               ans = max(ans, rec(i,j,dp,matrix));
            }
            // cout<<endl;
        }
        return ans;
        
    }
};