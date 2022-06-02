class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size();
        long long int mul = 1; 
        long long int ans = 0;
        for(int i=n-1; i>=0; i--){
            int val = s[i]-'A';
            ans+= mul*(val+1);
            mul*=26;
        }
        return ans;
    }
};