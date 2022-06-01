class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            vector<int> arr(26,0);

            for (char x: s)
            {
                arr[x - 'a']++;
            }
            for (char x: t)
            {
                arr[x - 'a']--;
            }
            for (int i = 0; i < 26; i++)
            {
                if (arr[i])
                {
                    return false;
                }
            }
            return true;
        }
};