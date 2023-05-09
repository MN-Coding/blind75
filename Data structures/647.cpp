/*
Problem: 647. Palindromic Substrings
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), count = 0;
        int dp[n][n];
        for (int length = 1; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                if (length == 1) {
                    dp[i][i] = 1;
                } else if (length == 2) {
                    dp[i][i+1] = s[i] == s[i+1] ? 1 : 0;
                } else if (s[i] == s[i + length - 1] && dp[i+1][i+length-2] > 0) {
                    dp[i][i+length - 1] = 1;
                } else {
                    dp[i][i+length - 1] = 0;
                }
                count += dp[i][i + length - 1];
            }
        }
        return count;
    }
};
