/*
Problem: 1. Two Sum
Time Complexity = O(n)
Space Complexity = O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> pairs;
        for (int i = 0; i < nums.size(); i++) {
            if (pairs.find(nums[i]) != pairs.end()) {
                return {i, pairs[nums[i]]};
            }
            pairs[target - nums[i]] = i;
        }
        return {-1, -1};
    }
};
