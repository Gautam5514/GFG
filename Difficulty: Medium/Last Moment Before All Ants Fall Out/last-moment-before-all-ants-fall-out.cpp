class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
          int lastTime = 0;

        // Ants moving left
        for (int pos : left) {
            lastTime = max(lastTime, pos);
        }

        // Ants moving right
        for (int pos : right) {
            lastTime = max(lastTime, n - pos);
        }

        return lastTime;
        
    }
};