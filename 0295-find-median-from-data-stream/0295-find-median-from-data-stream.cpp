
class DataDash {
public:
    int sum = 0;
    int sumSq = 0;
    int n = 0 ;
    map<int, int> freq;
    multiset<pair<int, int>> freqPair;
    multiset<int> left, right;

    void balance() {
        if(left.size() < right.size()) {
            int x = *right.begin();
            left.insert(x);
            right.erase(right.find(x));
        }
        if(left.size() > right.size() + 1) {
            int x = *left.rbegin();
            right.insert(x);
            left.erase(left.find(x));
        }
    }
    void insert(int x) {

        //median
        if(left.size() == 0)
            left.insert(x);
        else if(x > *left.rbegin()) {
            right.insert(x);
        } else {
            left.insert(x);
        }
        balance();


    }
    void remove(int x) {

        //median

        if(left.find(x) != left.end())
            left.erase(left.find(x));

        else
            right.erase(right.find(x));
        balance();
    }

    double median() {
        if(left.size() == right.size())
            return (double)(*left.rbegin() + *right.begin()) / 2;
        else return
               (double) *left.rbegin();
    }

   
};



class MedianFinder {
public:DataDash d;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        d.insert(num);
    }
    
    double findMedian() {
        return d.median();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */