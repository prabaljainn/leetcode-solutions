class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s(arr1.begin(), arr1.end());
        vector<int> ans;
        ans.reserve(min(arr1.size(), arr2.size()));
        
        for(int x: arr2){
            if(s.erase(x) > 0 )
            {
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};