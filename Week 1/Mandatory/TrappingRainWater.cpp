class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);
        left[0] = 0, right[n - 1] = 0;
        int max_left = height[0], max_right = height[n - 1], sum = 0;
        for (int i = 1; i < n; i++) {
            left[i] = max_left;
            if (height[i] > max_left)
                max_left = height[i];
        }
        for (int i = n - 2; i > -1; i--) {
            right[i] = max_right;
            if (height[i] > max_right)
                max_right = height[i];
        }
        for (int i = 0; i < n; i++) {
            sum += max((min(left[i], right[i]) - height[i]), 0);
        }
        return sum;
    }
};
