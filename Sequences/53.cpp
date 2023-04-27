/*
Problem: 53. Maximum Subarray
Time Complexity = O(n)
Space Complexity = O(1)
*/

// Kadane's Algorithm
class Solution {
public:    
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currMax = 0;
        for (int i = 0; i < nums.size(); i++) {
            currMax += nums[i];
            maxSum = max(maxSum, currMax);
            currMax = max(currMax, 0);
        }
        return maxSum;
    }
};
