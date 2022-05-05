class Solution
{
    public:
        int a, b, x;
    int inf = 1e9;
    int dp[6005][2];
    set<int> st;
    int rec(int pos, int cnt)
    {
        if (pos == x)
            return 0;
        if (st.count(pos) or pos < 0 or pos > 6000)
            return inf;
       	//returns the min num of steps to take to reach at x


        if (dp[pos][cnt] != -1)
            return dp[pos][cnt];

        dp[pos][cnt] = 1 + rec(pos + a, 0);
        return dp[pos][cnt] = min(dp[pos][cnt], cnt == 0 ? 1 + rec(pos - b, 1) : dp[pos][cnt]);
       
        // int ans = 1+ rec(pos+a,0);
        // if(cnt ==0)
            // ans = min(ans, 1+ rec(pos-b, 1));
       // return dp[pos][cnt] = min(ans, cnt == 0 ? 1 + rec(pos - b, 1) : ans);
    }
    int minimumJumps(vector<int> &f, int A, int B, int X)
    {
        st = set<int> (f.begin(), f.end());
        memset(dp, -1, sizeof(dp));
        a = A;
        b = B;
        x = X;

        if (rec(0, 0) > inf)
            return -1;
        return rec(0, 0);
    }
};

