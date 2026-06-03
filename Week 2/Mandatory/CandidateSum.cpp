class Solution {
public:
    void backtrack(vector<int>& candidates, vector<vector<int>>& res, vector<int>& path, int target, int idx, int sum) {

        // when the target sum is reached, we add the path to the result
        if (sum == target) {
            res.push_back({path});
            return;
        }

        // if target sum is exceeded, then stop traversing the tree
        if (sum > target)
            return;

        for (int i = idx; i < candidates.size(); i++) {

            // traverse down
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, res, path, target, i, sum);

            // backtrack
            path.pop_back();
            sum -= candidates[i];
        }
    }

    // main function
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end(), greater<int>());

        backtrack(candidates, res, path, target, 0, 0);

        return res;
    }
};
