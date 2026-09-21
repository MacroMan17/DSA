class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        int dirx[] = {0, 0, 1, -1};
        int diry[] = {1, -1, 0, 0};
        dist[0][0] = 0;
        dq.push_front({0, 0});
        while (!dq.empty()) {
            int dr = dq.front().first;
            int dc = dq.front().second;
            dq.pop_front();
            for (int i = 0; i < 4; i++) {
                int n_dr = dr + dirx[i];
                int n_dc = dc + diry[i];
                if (n_dr >= 0 && n_dr < m &&
                    n_dc >= 0 && n_dc < n) {
                    int cost;
                    if (grid[dr][dc] == i + 1) {
                        cost = 0;
                    } else {
                        cost = 1;
                    }
                    if (dist[dr][dc] + cost < dist[n_dr][n_dc]) {
                        dist[n_dr][n_dc] =
                            dist[dr][dc] + cost;
                        if (cost == 0) {
                            dq.push_front({n_dr, n_dc});
                        } else {
                            dq.push_back({n_dr, n_dc});
                        }
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};