class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, freq = 0;
        for(int val : nums){
            if(freq == 0) ans = val;
            if(ans == val) freq++;
            else freq--;
        }
        return ans;
    }
};
