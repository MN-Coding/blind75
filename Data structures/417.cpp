/*
Problem: 417. Pacific Atlantic Water Flow
Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/

class Solution {
public:
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col) {
        int m = heights.size();
        int n = heights[0].size();
        visited[row][col] = true;
        if (row > 0 && !visited[row - 1][col] && heights[row - 1][col] >= heights[row][col]) {
            dfs(heights, visited, row - 1, col);
        }
        if (row < m - 1 && !visited[row + 1][col] && heights[row + 1][col] >= heights[row][col]) {
            dfs(heights, visited, row + 1, col);
        }
        if (col > 0 && !visited[row][col - 1] && heights[row][col - 1] >= heights[row][col]) {
            dfs(heights, visited, row, col - 1);
        }
        if (col < n - 1 && !visited[row][col + 1] && heights[row][col + 1] >= heights[row][col]) {
            dfs(heights, visited, row, col + 1);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> canFlowAtlantic(m, vector<bool>(n));
        vector<vector<bool>> canFlowPacific(m, vector<bool>(n));
        vector<vector<int>> results;
        for (int i = 0; i < m; i++) {
            dfs(heights, canFlowAtlantic, i, n-1);
            dfs(heights, canFlowPacific, i, 0);
        }
        for (int i = 0; i < n; i++) {
            dfs(heights, canFlowAtlantic, m-1, i);
            dfs(heights, canFlowPacific, 0, i);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (canFlowPacific[i][j] && canFlowAtlantic[i][j]) {
                    results.push_back({i, j});
                }
            }
        }
        return results;
    }
};
