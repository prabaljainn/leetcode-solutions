class Solution
{
    public:

    bool palindrome(string s, int i , int j) {
        while(i<j){
            if(s[i] != s[j])
                return false;
            i++; j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int i = 0;
        int j = s.length()-1;
        int cnt = 0;
        
        while(i<j){
            if(s[i] != s[j]) {
                return (palindrome(s,i+1,j)or(palindrome(s,i,j-1)));
            }
            
            i++; j--;
        }
        return true;
    }
};
