class Solution
{
     int dx[4] = { 1,0,-1,0};
     int dy[4] = { 0,1,0,-1};
    vector<vector < int>> arr;
    bool check(int i, int j, int n, int m){
        if(i<0 or j<0 or i>=n or j>=m or arr[i][j]!=1)
            return false;
        
        return true;
    }
    public:
        int orangesRotting(vector<vector < int>> &arr)
        {
            this->arr = arr;
            int n = arr.size();
            int m = arr[0].size();
            vector<vector < int>> dis(n, (vector<int> (m)));
           	//         n *m matrix n rows

            queue<pair<int, int>> q;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    
                    if (arr[i][j] == 2)
                    {
                        dis[i][j] = 0;
                        q.push(make_pair(i, j));
                    }
                    else if(arr[i][j] == 0){
                        dis[i][j]=0;
                    }
                    else{
                        dis[i][j]= 1e9;
                    }
                }
            }
            while(!q.empty()){
                pair<int,int> p = q.front(); q.pop();
                for(int ii=0; ii<4; ii++){
                    int i = p.first + dx[ii];
                    int j = p.second + dy[ii];
                    if(check(i,j,n,m)){
                        
                        if(dis[i][j] > dis[p.first][p.second]+1){
                            // cout<<i<< " "<<j<<endl;
                            q.push(make_pair(i,j));
                            dis[i][j]= dis[p.first][p.second]+1;
                            arr[i][j] = 2;
                        }
                    }
                }
            }

            int ans =0;
            
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if(arr[i][j]!=0)
                    ans = max(ans, dis[i][j]);
                    // cout<<dis[i][j]<<" ";
                }
                // cout<<endl;
            }
            if(ans==1e9)
                return -1;
            return ans;
            
        }
};