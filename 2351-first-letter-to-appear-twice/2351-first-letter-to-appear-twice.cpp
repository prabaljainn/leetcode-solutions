class Solution {
public:
    char repeatedCharacter(string s) {
        int arr[26];
        memset(arr, 0, sizeof(arr));
        
        for(char x: s)
        {
            if(arr[x-'a']==1)
                return x;
            arr[x-'a']++;
        }
        return 'a';
        
    }
};