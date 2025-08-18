class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        
        sort(citations.begin(), citations.end());
        int h = 0;
        
        for(int i = 0; i < n; i++) {
            int paper = n - i;
            h = max(h, min(citations[i], paper));
        }
        return h;
    }
};