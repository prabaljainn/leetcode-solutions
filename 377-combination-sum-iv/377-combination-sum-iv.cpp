class Solution {
    int dp[1000100];
    vector<int> arr;
    int n;
    int rec(int level ){
        if(level ==0 )
            return 1;
        
        if(dp[level]!= -1)
            return dp[level];
        
        //computataion
        int ans=0;
        for(int i=0 ; i<n; i++  ){
            if(level - arr[i] >= 0)
            ans+=  rec(level - arr[i]);
        }
        return dp[level] = ans;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        arr.resize(nums.size());
        arr = nums;
        memset(dp,-1,sizeof(dp));
        return rec(target);
    }
};