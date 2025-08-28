class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int left = 0, zeroCount = 0, maxLen = 0;
        
        for(int right = 0; right < n; right++) {
            if(arr[right] == 0) zeroCount++;
            
            while(zeroCount > k) {
                if(arr[left] == 0 ) zeroCount--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};


// int n = arr.size();
//         int maxLen = 0;
        
//         for(int i = 0; i < n; i++) {
//             int zero = 0;
            
//             for(int j = i; j < n; j++) {
//                 if(arr[j] == 0) {
//                     zero++;
//                 }
//                 if(zero > k) {
//                     break;
//                 }
//                 maxLen = max(maxLen, j - i + 1);
//             }
//         }
//         return maxLen;