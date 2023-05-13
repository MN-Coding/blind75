/*
Problem: 207. Course Schedule
Time Complexity: O(v + e)
Space Complexity: O(v + e)
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> graph;
        map<int, int> indegree;
        for (int i = 0; i < numCourses; i++) {
            indegree[i] = 0;
            vector<int> pres;
            graph[i] = pres;
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        }
        queue<int> q;
        for (auto i: indegree) {
            if (i.second == 0) {
                q.push(i.first);
            }
        }
       vector<bool> visited(numCourses, false);
        while (!q.empty()) {
            int currCourse = q.front();
            q.pop();
            visited[currCourse] = true;
            for (int i = 0; i < graph[currCourse].size(); i++) {
                indegree[graph[currCourse][i]]--;
                if (indegree[graph[currCourse][i]] == 0) {
                    q.push(graph[currCourse][i]);
                }
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};
