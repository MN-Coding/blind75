/*
Problem: 242. Valid Anagram
Time Complexity = O(n)
Space Complexity = O(1)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int arr[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) return false;
        }
        return true;
    }
};