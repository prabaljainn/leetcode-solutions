class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
    int n = points.size();
        
    for(int i = 0; i < k; i++) {
        int x, y;
        x = points[i][0];
        y = points[i][1];
        int dis  = (x * x) + (y * y);
        pq.push({dis,{x,y}});
    }
    for(int i = k; i < n; i++) {
        int x, y;
       x = points[i][0];
        y = points[i][1];
        int dis  = (x * x) + (y * y);
        auto elem = pq.top();
        if(dis < elem.first) {
            pq.pop();
            pq.push(make_pair(dis, make_pair(x, y)));

        } else if(dis == elem.first) {
            if(x < elem.second.first) {
                pq.pop();
                pq.push(make_pair(dis, make_pair(x, y)));

            }
        }
        
    }
        vector<vector<int>> ans;
    while (!pq.empty()){
        auto elems = pq.top();
        pq.pop();
        vector<int> v;
        v.push_back(elems.second.first);
        v.push_back(elems.second.second);
        ans.push_back(v);
    }
    reverse(ans.begin(),ans.end());
return ans;}
};