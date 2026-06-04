class Solution {
public:
    void backtrack(vector<string>& res, string& path, int n, int fwd, int bwd) {
        if (fwd == n && bwd == n) {
            res.push_back(path);
            return;
        }
        if (fwd < n) {
            path.push_back('(');
            backtrack(res, path, n, fwd + 1, bwd);
            path.pop_back();
        }
        if (bwd < fwd) {
            path.push_back(')');
            backtrack(res, path, n, fwd, bwd + 1);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path = "";
        backtrack(res, path, n, 0, 0);
        return res;
    }
};
