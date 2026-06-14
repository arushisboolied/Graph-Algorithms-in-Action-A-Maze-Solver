class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i : nums)
            s.insert(i);
        int ans = 0;
        for(int i : s){
            if(!s.count(i - 1)){
                int size = 0;
                while(s.count(i + size))
                    size++;
                ans = max(ans,size);
            }
        }
        return ans;
    }
};
