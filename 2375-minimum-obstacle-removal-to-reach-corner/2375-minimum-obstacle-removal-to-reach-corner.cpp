using int2 = pair<int, int>; 
const static int d[5] = {0, 1, 0, -1, 0};
class Solution {
public:
    inline static bool isOutside(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }
    inline static int idx(int i, int j, int m){
        return i*m+j;
    }

    static int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unsigned dist[100000];
        fill(dist, dist+n*m, INT_MAX);
        priority_queue<int2, vector<int2>, greater<int2>> pq;

        pq.emplace(0, 0);
        dist[0] = 0;

        while (!pq.empty()) {
            auto [currD, ij] = pq.top();
            auto [i, j]=div(ij, m);
            pq.pop();

            if (i == n - 1 && j == m - 1)
                return currD;

            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m))
                    continue;

                int nextD = grid[r][s] + currD;

                int rs=idx(r, s, m);
                if (nextD < dist[rs]) {
                    dist[rs] = nextD;
                    pq.emplace(nextD, rs);
                }
            }
        }
        return -1; 
    }
};
