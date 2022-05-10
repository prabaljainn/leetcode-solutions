class Solution {
public:
    vector<vector<int>>g;
    vector<int> color;
    bool flag= true;
    
    void dfs(int node, int col){
        if(color[node]!=0)
            return;
        color[node] = col;
        
        for(int nodes: g[node]){
            if(color[nodes]==col)
                {flag= false;
                return ;}
            if(col==1)
                dfs(nodes, 2);
            else
                dfs(nodes, 1);
        }
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        g.resize(n+1);
        for(auto elem: dislikes){
            g[elem[0]].push_back(elem[1]);
            g[elem[1]].push_back(elem[0]);
        }
        
        color.assign(n+1,0);
        
        
        for(int i=1; i<=n; i++){
            if(color[i]==0)
                dfs(i, 1);
            if(flag==false)
                return false;
        }
        return true;
        
    }
};