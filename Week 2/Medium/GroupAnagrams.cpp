class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;

        // we create a copy vector, and sort all the strings in it so that the
        // anagrams are apparent
        vector<string> copy = strs;
        for (auto& val : copy)
            sort(val.begin(), val.end());

        // now, we store indices of matching strings in the copy vector using a
        // hash table
        unordered_map<string, vector<int>> h;
        for (int i = 0; i < copy.size(); i++)
            h[copy[i]].push_back(i);

        // iterating over the hash table will give us anagrams in strs
        for (const auto& [key, value] : h) {
            vector<string> path;

            for (int i = 0; i < value.size(); i++) 
                path.push_back(strs[value[i]]);
    
            ans.push_back(path);
        }
        
        return ans;
    }
};
