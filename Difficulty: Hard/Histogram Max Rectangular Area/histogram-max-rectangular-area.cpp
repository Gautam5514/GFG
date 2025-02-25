//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int l = arr.size();
        int area = 0;
        stack<int> st;
        
        for(int i = 0; i < l; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                int height = arr[st.top()];
                st.pop();
                int width = (st.empty()) ? i : i - st.top() - 1;
                area = max(area, height * width);
            }
            st.push(i);
        }
        while(!st.empty()) {
            int height = arr[st.top()];
            st.pop();
            int width = (st.empty()) ? l : l - st.top() - 1;
            area = max(area, height * width);
        }
        return area;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends