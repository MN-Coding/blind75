/*
Problem: 200. Number of Islands
Time Complexity: O(nm)
Space Complexity: O(nm) ~function stack
*/

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }
        if(grid[i][j] == '2' || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '2';
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int retval = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    retval++;
                    dfs(grid, i, j);
                }
            }
        }
        return retval;
    }
};
