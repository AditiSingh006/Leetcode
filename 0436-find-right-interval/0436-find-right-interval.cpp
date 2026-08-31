class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<pair<int, int>> starts;

        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }

        // Sort by start
        sort(starts.begin(), starts.end());

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];

            // Find first start >= end
            int low = 0, high = n - 1;
            int idx = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (starts[mid].first >= end) {
                    idx = starts[mid].second;
                    high = mid - 1;
                } 
                else {
                    low = mid + 1;
                }
            }

            ans[i] = idx;
        }

        return ans;
    }
};