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
        if (start>=(*prev).second and end<=(*curr).first)
        {
            s.insert({ start,
                end });
            return true;
        }
        
        return false;
    }
};

/**
 *Your MyCalendar object will be instantiated and called as such:
 *MyCalendar* obj = new MyCalendar();
 *bool param_1 = obj->book(start,end);
 */