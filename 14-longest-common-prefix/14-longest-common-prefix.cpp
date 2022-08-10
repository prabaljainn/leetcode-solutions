class Solution
{
    public:
        string longestCommonPrefix(vector<string> &arr)
        {
            int n = 0;
            for (string elem: arr)
                n = max(n, (int) elem.size());
            string s = "";
            for (int i = 0; i < n; i++)
            {
                bool flag = true;
                char val = ((arr[0])[i]);
                for (string elem: arr)
                {
                    if (elem[i] != val)
                        flag = false;
                }
                if (flag == false)
                {
                    break;
                }
                s += val;
            }
            return s;
        }
};