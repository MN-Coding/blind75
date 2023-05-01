/*
Problem: 49. Group Anagrams
Time Complexity = O(nklog(k))
Space Complexity = O(nk)
where n = strs.length, k = max(strs[i].length)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> retval;
        unordered_map<string, vector<string>> groups;
        string curr;
        for (int i = 0; i < strs.size(); i++) {
            curr = strs[i];
            sort(curr.begin(), curr.end());
            groups[curr].emplace_back(strs[i]);
        }
        for (auto x: groups) {
            retval.emplace_back(x.second);
        }
        return retval;
    }
};
