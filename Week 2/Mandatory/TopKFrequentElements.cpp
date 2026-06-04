class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freqs;
        for (auto val : nums)
            freqs[val]++;
        vector<pair<int, int>> sorted(freqs.begin(), freqs.end());
        sort(sorted.begin(), sorted.end(),
             [](const auto& a, const auto& b) { return a.second > b.second; });
        vector<int> ans(k, 0);
        for (int i = 0; i < k; i++)
            ans[i] = sorted[i].first;
        return ans;
    }
};
