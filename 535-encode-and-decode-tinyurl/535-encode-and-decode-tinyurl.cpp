class Solution {
public:
     int iter =0;
    // Encodes a URL to a shortened URL.
    map<string,string > map1;
    map<string,string > map2;
    
    string encode(string longUrl) {
        map1[to_string(iter)] = longUrl;
        
        map2[longUrl] = to_string(iter);
        
        iter++;
        
        return to_string(iter-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map1[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));