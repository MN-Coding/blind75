/*
Problem: 3. Longest Substring Without Repeating Characters
Time Complexity: O(n)
Space Complexity: O(1) ~Map = O(26)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=0 , maxlength=0, j=0;
        map<char ,int> mp;
        for(int i=0 ;i<s.size(); i++){
            mp[s[i]]++;
            length++;
                while(mp[s[i]]>1){
                    mp[s[j++]]--;
                    length--;
                }
            maxlength = max(maxlength,length);
        }
        return maxlength;
    }
};
