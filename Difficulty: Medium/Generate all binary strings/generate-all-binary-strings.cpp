class Solution {
  public:
    vector<string> binstr(int n) {
        // code here
        // total no of find 2n has been generate 
        // if n = 6, means 2n (2 * 6) = 128, n = 2, (2, 2) => 4
        
        vector<string> result;
        int total = 1 << n;
        
        for(int i = 0; i < total; i++) {
            string binary = bitset<20>(i).to_string();
            
            result.push_back(binary.substr(20 - n));
        }
        return result;
    }
};