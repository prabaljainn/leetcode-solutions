class Solution
{
    public:
        bool dp[22];
    bool vis[22];
    map<string, bool> m;
    string s;
    bool rec(int level)
    {
        int n = s.size();
        if (level == n)
            return true;
        if (vis[level] == true)
            return dp[level];
        vis[level] = true;
        for (int i = level; i < n; i++)
        {
            if (m[s.substr(level, i - level + 1)]== true and rec(i + 1) == true)
                dp[level] = true;
        }
        return dp[level];
    }
    vector<string> ans;
    void rec2(int level, string str)
    {
        int n = s.size();
        if (level == s.size())
            return ans.push_back(str);

        for (int i = level; i < n; i++)
        {
            if (m[s.substr(level, i - level + 1)]== true and rec(i + 1) == true)
            {
                string temp = str;
                if(level>0)str+= " ";
                str += s.substr(level, i - level + 1);
                rec2(i + 1, str);
                str = temp;
                
            }
        }
    }

    vector<string> wordBreak(string S, vector<string> &wordDict)
    {
        memset(vis, false, sizeof(vis));
        
        for(auto x: wordDict)
            m[x] = true;
        s = S;
       	// cout<<(rec(0,wordDict));
        rec2(0, "");

        return ans;
    }
};