class Solution {
public:
    int check(vector<int>& weights, int days, int capacity) {
        int sum = 0, count = 0;
        for (int val : weights) {
            if (sum + val > capacity) {
                sum = 0;
                count++;
            }
            sum += val;
        }
        count++;
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for (int val : weights)
            sum += val;
        int l = *max_element(weights.begin(), weights.end()), r = sum;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (check(weights, days, m) <= days)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
