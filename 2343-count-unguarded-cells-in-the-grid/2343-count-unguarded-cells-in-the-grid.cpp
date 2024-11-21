class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0)); 
        for (auto& wall : walls) {
            vis[wall[0]][wall[1]] = 1;
        }
        for (auto& guard : guards) {
            vis[guard[0]][guard[1]] = 2;
        }
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& guard : guards) {
            int row = guard[0], col = guard[1];
            for (auto& dir : directions) {
                int r = row + dir.first, c = col + dir.second;
                while (r >= 0 && r < m && c >= 0 && c < n && vis[r][c] != 1 && vis[r][c] != 2) {
                    if (vis[r][c] == 0) vis[r][c] = -1;
                    r += dir.first;
                    c += dir.second;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j] == 0) {
                    ++count;
                }
            }
        }
        return count;
    }
};
