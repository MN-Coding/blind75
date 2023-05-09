/*
Problem: 435. Non-overlapping Intervals
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/


class Solution {
public:

    static bool compare(vector<int> &a,vector<int> &b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        int count = 1, currFinish = intervals[0][1];
        for (int i = 0; i < n; i++) { 
            if (intervals[i][0] >= currFinish) {
                count++;
                currFinish = intervals[i][1];
            }
        }
        return n - count;
    }
};
