class Solution
{
    public:
        bool checkInclusion(string s1, string s2)
        {
            if(s1.size()>s2.size())
                return false;
            int win_size = s1.size();
            int n = s2.size();
            vector<int> v(26, 0);
            vector<int> v2(26, 0);

            for (char x: s1)
            {
                v[x - 'a']++;
            }
            
            
            for (int i = 0; i < win_size; i++)
            {
                v2[s2[i] - 'a']++;
            }
            
            if (v == v2)
                return true;
            
            for (int i = win_size; i < n; i++)
            {
                v2[s2[i] - 'a']++;
                v2[s2[i - win_size] - 'a']--;

                if (v == v2)
                    return true;
            }
            return false;
        }
};