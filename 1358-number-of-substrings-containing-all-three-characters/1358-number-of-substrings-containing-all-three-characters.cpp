class Solution
{
    public:
        int numberOfSubstrings(string s)
        {
            int head = -1;
            int tail = 0;
            int ans = 0;
            map<char, int> mp;
            while (tail < s.length())
            {

                while (head + 1 < s.length() and mp.size() < 3)
                {
                    head++;
                    mp[s[head]]++;
                }
                
                
                
                if (mp.size() == 3)

                    ans += (s.length() - head);

                
                
                if (head >= tail)
                {
                    mp[s[tail]]--;
                    if (mp[s[tail]] == 0) mp.erase(s[tail]);
                    tail++;
                }
                else
                {
                    mp[s[tail]]--;
                    if (mp[s[tail]] == 0) mp.erase(s[tail]);
                    tail++;
                    head = tail - 1;
                }
            }
            return ans;
        }
};