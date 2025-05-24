class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
           int n = s.size();
        long long sum = 0;
        string temp;

        for (int i = 0; i < n; i++) {
            temp = "";
            for (int j = i; j < n; j++) {
                temp += s[j];
                sum += stoll(temp);
            }
        }
        return sum;
    }
};