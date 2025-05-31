class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
          priority_queue<int>pq;
        for(auto x:matrix){
            for(auto y:x){
                pq.push(y);
                if(pq.size()>k)pq.pop();
            }
        }
        return pq.top();
    }
};