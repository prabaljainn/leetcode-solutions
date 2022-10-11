

class MedianFinder
{
    public: 
    multiset<int> left, right;

    void balance()
    {
        if (left.size() < right.size())
        {
            int x = *right.begin();
            left.insert(x);
            right.erase(right.find(x));
        }
        if (left.size() > right.size() + 1)
        {
            int x = *left.rbegin();
            right.insert(x);
            left.erase(left.find(x));
        }
    }
    void addNum(int x)
    {

       	//median
        if (left.size() == 0)
            left.insert(x);
        else if (x > *left.rbegin())
        {
            right.insert(x);
        }
        else
        {
            left.insert(x);
        }
        balance();
    }

    double findMedian()
    {
        if (left.size() == right.size())
            return (double)(*left.rbegin() + *right.begin()) / 2;
        else return (double) *left.rbegin();
    }
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */