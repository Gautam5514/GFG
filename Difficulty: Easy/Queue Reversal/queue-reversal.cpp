class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        if(q.size() == 0) return;
        int tmp = q.front();
        q.pop();
        reverseQueue(q);
        q.push(tmp);
    }
};