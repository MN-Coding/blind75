/*
Problem: 238. Product of Array Except Self
Time Complexity: O(n)
Space Complexity: 
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> retval(n);
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 1;
        right[n-1] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i-1];
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i+1] * nums[i+1];
        }
        for (int i = 0; i < n; i++) {
            retval[i] = left[i] * right[i];
        }
        return retval;

    }
};
