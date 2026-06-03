class Solution {
public:
    // check whether a particular [row, col] position is valid or not
    // we only need to check rows above the row we are currently at because the
    // rows below are not yet filled (beauty of backtracking)
    bool isValid(const vector<string>& path, int row, int col, int n) {

        // use these variables to traverse
        int i, j;

        // checking row
        j = col;
        while (j > -1) {
            if (path[row][j] == 'Q')
                return false;
            j--;
        }

        // checking column
        i = row;
        while (i > -1) {
            if (path[i][col] == 'Q')
                return false;
            i--;
        }

        // checking positive diagonal
        i = row, j = col;
        while (i > -1 && j < n) {
            if (path[i][j] == 'Q')
                return false;
            i--;
            j++;
        }

        // checking negative diagonal
        i = row, j = col;
        while (i > -1 && j > -1) {
            if (path[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        return true;
    }

    // adds a row to the path
    void backtrack(int n, vector<vector<string>>& res, vector<string>& path,
                   int row) {

        // when we exceed the row limit, that means the even the (n - 1)th row
        // was approved. so we append it.
        if (row == n) {
            res.push_back({path});
            return;
        }

        // check all possible positions for each row
        for (int i = 0; i < n; i++)
            if (isValid(path, row, i, n)) {
                path[row][i] = 'Q';
                backtrack(n, res, path, row + 1);
                path[row][i] = '.';
            }
    }

    // main function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> path(n, string(n, '.'));

        // NOTE : Rows and Columns are [0,1,2...,n-1]

        backtrack(n, res, path, 0);

        return res;
    }
};
