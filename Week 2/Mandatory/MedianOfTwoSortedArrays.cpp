class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size())
            return findMedianSortedArrays(B, A);
        int m = A.size(), n = B.size();
        int total = m + n;
        int half = (total + 1) / 2;
        int l = 0, r = m;
        while (true) {
            int i = (l + r) / 2;
            int j = half - i;
            int A_left = (i == 0) ? INT_MIN : A[i - 1];
            int A_right = (i == m) ? INT_MAX : A[i];
            int B_left = (j == 0) ? INT_MIN : B[j - 1];
            int B_right = (j == n) ? INT_MAX : B[j];
            if (A_left <= B_right && B_left <= A_right) {
                if (total % 2 == 1)
                    return max(A_left, B_left);
                return (max(A_left, B_left) + min(A_right, B_right)) / 2.0;
            } else if (A_left > B_right)
                r = i - 1;
            else
                l = i + 1;
        }
    }
};
