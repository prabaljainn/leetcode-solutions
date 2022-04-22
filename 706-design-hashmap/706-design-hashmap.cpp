class MyHashMap {
public:
    vector<list<pair<int, int>>> v;
    int numElements;
    /** Initialize your data structure here. */
    MyHashMap() {
        numElements = 0;
        v.resize(20);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        //if load factor > 0.5
        if((double)(numElements / v.size()) > 0.5) grow();
        auto &list = v[key % v.size()];
        auto it = list.begin();
        while(it != list.end()){
            if(it->first == key) it->second = value;
            ++it;
        }
        
        if(it == list.end()){
            list.push_back(make_pair(key, value));
            ++numElements;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto &list = v[key % v.size()];
        auto it = find_if(list.begin(), list.end(), [key](auto x){
           return x.first == key; 
        });
        return (it == list.end()) ? -1 : it->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &list = v[key%v.size()];
        list.remove_if([key, this](auto x) { 
            if(x.first == key){
                --numElements;
                return true;
            }
            return false;
        });
    }
    
    void grow(){
        vector<list<pair<int, int>>> v2;
        v2.resize(v.size());
        v.swap(v2);
        v.resize(v.size() * 2);
        numElements = 0;
        for(auto l : v2){
            auto it = l.begin();
            while(it != l.end()){
                put(it->first, it->second);
                ++it;
            }
        }
    }
    
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */