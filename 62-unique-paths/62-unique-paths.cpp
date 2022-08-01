class Solution {
public:
    int dp[101][101];
    
    int rec(int m, int n){   // returns the number of ways you can reach 1,1
        if(m<=0 or n<=0)
            return 0;
        
        if(m==1 and n==1)
            return 1;
        
        if(dp[m][n]!= -1)
            return dp[m][n];
        
        return dp[m][n] = rec(m-1,n) + rec(m,n-1);
        
    }
    int uniquePaths(int m, int n) {
        
        for(int i=0; i<=m; i++)
            for(int j=0; j<=n; j++)
                dp[i][j] = -1;
        
        return rec(m,n);
    }
};