class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int> dq;
        vector<int> result;
        
        for(int i = 0; i < arr.size(); i++) {
            
            // remove element out of current window
            if(!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            // remove all smaller element from the back
            while(!dq.empty() && arr[dq.back()]  <= arr[i]) {
                dq.pop_back();
            }
            // insert curr index
            dq.push_back(i);
            
            // store result once window size is reached
            if(i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }
        return result;
    }
};

// < i - k + 1
// arr[deque.back()] <= arr[i]
// push the current index
// store answer