class Solution {
public:
    string smallestWindow(string &s, string &p) {
        if (p.size() > s.size()) return "";

        // Step 1: Count frequency of chars in p
        vector<int> freqP(256, 0), freqS(256, 0);
        for (char c : p) freqP[c]++;

        int required = p.size(); // total chars needed
        int start = 0, minLen = INT_MAX, minStart = -1;
        int count = 0;

        // Step 2: Sliding window
        for (int end = 0; end < s.size(); end++) {
            char c = s[end];
            freqS[c]++;

            if (freqP[c] > 0 && freqS[c] <= freqP[c]) {
                count++;
            }

            // Step 3: Shrink window if valid
            while (count == required) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }

                // shrink
                char leftChar = s[start];
                freqS[leftChar]--;
                if (freqP[leftChar] > 0 && freqS[leftChar] < freqP[leftChar]) {
                    count--;
                }
                start++;
            }
        }

        if (minStart == -1) return "";
        return s.substr(minStart, minLen);
    }
};
