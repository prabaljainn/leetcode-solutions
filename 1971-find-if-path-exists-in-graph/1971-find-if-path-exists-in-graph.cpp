class Solution
{
    public:
        vector<int> Rank;
    vector<int> Parent;

    int findParent(int x)
    {
        if (Parent[x] == x)
            return x;
        
        return Parent[x] = findParent(Parent[x]);
    }
    
    void Merge(int x, int y)
    {
        int xa = findParent(x);
        int xb = findParent(y);
        if(xa==xb)
            return;
        
        if(Rank[xa] > Rank[xb])
        {
            Rank[xa]+=Rank[xb];
                Parent[findParent(y)] = xa;
        }
        else{
            Rank[xb]+=Rank[xa];
            Parent[findParent(x)] = xb;
            
        }
    }
    
    bool validPath(int n, vector<vector < int>> &edges, int source, int destination)
    {
        Parent.resize(n);
        Rank.assign(n, 1);
        iota(Parent.begin(),Parent.end(),0);
   
        for (const vector < int> &x : edges)
        {
            Merge(x[0], x[1]);
        }

        return findParent(source) == findParent(destination);
    }
};