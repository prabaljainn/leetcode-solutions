class Solution {
public:
    int trap(vector<int>& arr) {
        int n  = arr.size();
        stack<int> s;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            while(!s.empty())
            {
                int idx = s.top();
                if(arr[i] < arr[idx])
                    break;
                int node = s.top();
                s.pop();
                if(s.empty())
                    break;
                int dis  = i-s.top();
                dis-=1;
                ans+= (min(arr[i], arr[s.top()])-arr[node]) * dis;
            }
            
            s.push(i);
            
            
            
        }
        return ans;
        
    }
};