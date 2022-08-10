class Solution
{
    public:

        bool validPalindrome(string arr)
        {
            int i = 0;
            int j = arr.size() - 1;
            bool flag = false;

            while (i <= j)
            {
                if (arr[i] == arr[j])
                {
                    i++;
                    j--;
                    continue;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
                return true;
            flag = false;
            int store1 = i;
            int store2 = j;
            i++;
            
            while (i <= j)
            {
                if (arr[i] == arr[j])
                {
                    i++;
                    j--;
                    continue;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
                return true;
            flag = false;
            i = store1;
            j = store2-1;
            while (i <= j)
            {
                if (arr[i] == arr[j])
                {
                    i++;
                    j--;
                    continue;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
                return true;
            return false;
            
            
        }
};