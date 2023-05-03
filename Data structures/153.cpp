/*
Problem: 153. Find Minimum in Rotated Sorted Array
Time Complexity: O(logn)
Space Complexity: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
