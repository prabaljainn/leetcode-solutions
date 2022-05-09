class Solution {
public:
    int n,m,k;
    
    bool check (int day,vector<int>& arr){   // this returns me if we can make m bouq
        int count = 0; 
        int val  =0;
        for(int x: arr)
        {
            if(x<= day)
                count++;
            if(x>day)
                count = 0;
            if(count == k)
            {
                val++;
                count=0;
            }
        }
        if(val>=m)
            return true;
        else return false;
        
    }
    int minDays(vector<int>& bloomDay, int M, int K) {
        int lo = 1;
        
        
        n = bloomDay.size();
        m = M;
        k = K;
        
        if(n < m*k)
            return -1;
        //ans is sure
        
        int hi  = -1e9;
        for(int x: bloomDay)
            hi  = max(hi, x);
        int ans = hi;
        while(lo<= hi){
            int mid = lo+ (hi-lo)/2;
            if(check(mid,bloomDay)==true)
            {
                hi = mid-1;
                ans = mid;
            }
            else{
                lo = mid+1; 
            }
        }
        return ans;
        
    }
};