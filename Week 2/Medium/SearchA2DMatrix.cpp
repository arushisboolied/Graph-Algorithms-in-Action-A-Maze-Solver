class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        /*
        first, we find the row in log(m)
        our required row is the one in which the first element is less than
        or equal to target and the successive row's first element is greater
        than or equal to the target
        this is the largest row whose first element is lesser than target
        */

        int l = 0, r = matrix.size() - 1, row = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (matrix[m][0] == target)
                return true;
            if (matrix[m][0] < target) {
                row = m;
                l = m + 1;
            } else
                r = m - 1;
        }
        if (row == -1)
            return false;

        // now, we search within the row in log(n)

        l = 0, r = matrix[row].size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (matrix[row][m] == target)
                return true;
            if (matrix[row][m] < target)
                l = m + 1;
            if (matrix[row][m] > target)
                r = m - 1;
        }
        return false;
    }
};
