class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        vector<vector<int>> result;
        vector<int> previous = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> current = intervals[i];
            if (current[0] > previous[1]) {
                result.push_back(previous);
                previous = current;
            } else {
                previous[1] = max(previous[1], current[1]);
            }
        }
        result.push_back(previous);
        return result;
    }
};
