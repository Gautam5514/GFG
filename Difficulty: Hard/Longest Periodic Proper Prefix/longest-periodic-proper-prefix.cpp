class Solution {
  public:
    int getLongestPrefix(string &s) {
        // code here
        int n = s.size();
        int len = s.size() - 1;
        
        while(len) {
            int ptr = len;
            int i = 0;
            
            while(ptr < n) {
                if(s[ptr] == s[i]) {
                    i++;
                    ptr++;
                } else {
                    break;
                }
            }
            if(ptr == n) 
             return len;
             
             len--;
        }
        return -1;
    }
};