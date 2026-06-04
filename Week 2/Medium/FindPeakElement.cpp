class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        if (nums.size() == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2])
            return nums.size() - 1;

        int l = 1, r = nums.size() - 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m - 1] < nums[m] && nums[m + 1] < nums[m])
                return m;
            else if (nums[m - 1] < nums[m])
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};
