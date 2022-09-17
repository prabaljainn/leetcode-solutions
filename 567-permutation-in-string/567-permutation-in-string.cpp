class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        int a=s1.size();
        int n=s2.size();
    for(int i=0;i<=n-a;i++){
        string t=s2.substr(i,a);
     sort(t.begin(),t.end());
        if(t==s1)
            
            return true;
        
    }
        return false;}};