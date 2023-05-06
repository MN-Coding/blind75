/*
Problem: 424. Longest Repeating Character Replacement
Time Complexity: O(n)
Space Complexity: O(1) ~Map is O(26)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0,maxFreq = 0, maxLen = 0;
        unordered_map<char, int> mp;
        while(j < s.size()){
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            if((j-i+1) - maxFreq <= k){
                maxLen = max(maxLen, j-i+1);
                j++;
            }
            else if((j-i+1) - maxFreq > k){
                while((j-i+1) - maxFreq > k){
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return maxLen;
    }
};
