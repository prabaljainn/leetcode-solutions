class MyCalendar
{
    public:
     set<pair<int, int>> s;

    MyCalendar()
    {
        s.insert({1e9, 1e9});
    }

    bool book(int start, int end)
    {
        if (s.size()==1)
        {
            s.insert({ start,
                end });
            return true;
        }

        auto curr = s.lower_bound({ start, -1e9 });
        auto prev = curr;
        prev--;
int l = (*prev).second;
        int r = (*curr).first;

        if (start>=l and end<=r)
        {
            s.insert({ start,
                end });
            return true;
        }
        cout<<start<<"    "<<end<<endl;
        cout<<l<<endl;
        cout<<r<<endl;
        
        return false;
    }
};

/**
 *Your MyCalendar object will be instantiated and called as such:
 *MyCalendar* obj = new MyCalendar();
 *bool param_1 = obj->book(start,end);
 */