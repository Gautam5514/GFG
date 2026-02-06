class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
         sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int i = 0, j = 0, k = 0;
    int bestDiff = INT_MAX;
    int bestSum = INT_MAX;
    vector<int> ans(3);

    while (i < a.size() && j < b.size() && k < c.size()) {
        int x = a[i], y = b[j], z = c[k];

        int mx = max({x, y, z});
        int mn = min({x, y, z});
        int diff = mx - mn;
        int sum = x + y + z;

        if (diff < bestDiff || (diff == bestDiff && sum < bestSum)) {
            bestDiff = diff;
            bestSum = sum;
            ans = {x, y, z};
        }

        // Move pointer of minimum element
        if (mn == x) i++;
        else if (mn == y) j++;
        else k++;
    }

    sort(ans.rbegin(), ans.rend()); // decreasing order
    return ans;
    }
};