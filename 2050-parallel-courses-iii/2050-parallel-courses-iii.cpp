class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> g;
        g.resize(n);
        vector<int> dis(n,0);
        vector<int> inD(n,0);
        for(auto x: relations){
            int a = x[0];
            int b = x[1];
            g[a-1].push_back(b-1);
            inD[b-1]++;
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(inD[i]==0)
                {q.push(i);
                    dis[i]= time[i];
                
                }
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int x: g[curr]){
                dis[x] = max(dis[x], dis[curr]+ time[x]);
                inD[x]--;
                if(inD[x]==0)
                    q.push(x);
            }
        }
        
        return *max_element(dis.begin(), dis.end());
        
    
    
    
    
    }
};