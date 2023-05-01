/*
Problem: 56. Merge Intervals
Time Complexity = O(nlog(n))
Space Complexity = O(1)
*/

class Solution {
public:
    struct op {
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        }
    } ope;

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), ope);
        int n = intervals.size();
        vector<vector<int>> retval;
        int currFinish = intervals[0][1];
        int currStart = intervals[0][0];
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] > currFinish) {
                retval.push_back({currStart, currFinish});
                currStart = intervals[i][0];
            }
            if (intervals[i][1] > currFinish) {
                currFinish = intervals[i][1];
            }
        }
        retval.push_back({currStart, currFinish});
        return retval;
    }
};
