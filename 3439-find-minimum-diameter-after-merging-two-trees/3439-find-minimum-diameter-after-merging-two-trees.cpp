class Solution {
public:
    pair<int, int> bfs(int start, const vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int farthestNode = start;
        int maxDist = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > maxDist) {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }

        return {farthestNode, maxDist};
    }

    int computeDiameter(const vector<vector<int>>& adj) {
        auto [farthestNode1, dist1] = bfs(0, adj);
        auto [farthestNode2, diameter] = bfs(farthestNode1, adj);
        return diameter;
    }

    int findMinDiameterAfterMergingTrees(vector<vector<int>>& tree1Edges, vector<vector<int>>& tree2Edges) {
        int n = tree1Edges.size() + 1;
        int m = tree2Edges.size() + 1;

        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        for (const auto& edge : tree1Edges) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for (const auto& edge : tree2Edges) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int diameter1 = computeDiameter(adj1);
        int diameter2 = computeDiameter(adj2);

        return max({diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1});
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        return findMinDiameterAfterMergingTrees(edges1, edges2);
    }
};