class Solution
{
    public:
        string Normal(string s)
        {
            unordered_map<char, int> m;
            for (char x: s)
            {
                if (!m.count(x))
                    m[x] = m.size();
            }
            for (int i = 0; i < s.size(); i++)
            {
                s[i] = 'a' + m[s[i]];
            }
            return s;
        }
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        pattern = Normal(pattern);
        vector<string> ans;
        for (string word: words)
        {
            if (pattern == Normal(word))
                ans.push_back(word);
        }
        return ans;
    }
};