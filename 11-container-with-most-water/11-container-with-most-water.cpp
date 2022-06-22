class Solution {
public:
    int maxArea(vector<int>& arr) {
         int n = arr.size();
    int l = 0; 
    int r  = n-1;
    int ans = -1e9;
    while(l<=r){
        int dis = (r-l);
        ans = max(ans, (dis*(min(arr[l],arr[r]))));
        if(arr[l]<arr[r])
            l++;
        else
            r--;
    }
    return ans;
    }
};