class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n= s.size();
        int head = -1; int tail = 0;
        //len is head-tail +1;
        int ans =0 ; 
        unordered_set<int> se;
        while(tail<n){
            // take head upto max you can take
            while((head+1 < n) and (se.find(s[head+1])==se.end()) ){
                head++;
                se.insert(s[head]);
            }
            // update the ans;
            ans = max(ans, (head-tail+1));
                
            //update the tail
            if(tail <= head){
                    se.erase(s[tail]);
                    tail++;
                }
            else{
                tail++;
                head = tail-1;
            }
            
            
            
        }
        return ans;
        
    }
};