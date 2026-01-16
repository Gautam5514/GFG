class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        for (int i = 0; i < n; i++) {
            if (arr[i] == -1) continue;
            int L = max(0, i - arr[i]);
            int R = min(n - 1, i + arr[i]);
            intervals.push_back({L, R});
        }

        sort(intervals.begin(), intervals.end());

        int count = 0;
        int coveredTill = -1;   // last covered index
        int i = 0;

        while (coveredTill < n - 1) {
            int maxReach = coveredTill;

            while (i < intervals.size() && intervals[i].first <= coveredTill + 1) {
                maxReach = max(maxReach, intervals[i].second);
                i++;
            }

            if (maxReach == coveredTill) return -1;

            count++;
            coveredTill = maxReach;
        }

        return count;
    }
};
