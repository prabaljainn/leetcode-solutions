class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.size();
        // int tot = (n*(n+1))/2;
        // tot--;
        int head = -1; 
        int tail = 0;
        int val =0;
        map<char, int> mp;
        mp['a']=0;
        mp['b']=0;
        mp['c']=0;
        while(tail<n){
            
            while(
                (head+1<n) and (((mp['a']+(s[head+1]=='a') <1 )or
                (mp['b']+(s[head+1]=='b') <1) or
                (mp['c']+(s[head+1]=='c') <1))
            
            )
                 )
            {
                head++; 
                mp[s[head]]++;
            }
            
            val+= (n-head-1);
            cout<<val<<endl;
            
            if(tail<= head)
            {
                // if(mp[s[tail]]>0)
                mp[s[tail]]--;
                tail++;
            }
            else{
                // if(mp[s[tail]]>0)
                mp[s[tail]]--;
                tail++;
                head= tail-1;
            }
            
        }
        // cout<<(tot)<<" "<<val;
        return val;
        
    }
};