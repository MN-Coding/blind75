/*
Problem: 11. Container With Most Water
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int currMax = 0, n = height.size(), left = 0, right = n - 1;
        while (left < right) {
            currMax = max(currMax, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return currMax;
     }
};
