class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m = grid.size(), n = grid[0].size();
            vector<int> result(queries.size(), 0);
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            
            vector<pair<int, int>> queryIndex;
            for (int i = 0; i < queries.size(); i++) {
                queryIndex.push_back({queries[i], i});
            }
            sort(queryIndex.begin(), queryIndex.end());
    
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
            pq.push({grid[0][0], {0, 0}});
            visited[0][0] = true;
    
            int dx[4] = {0, 1, 0, -1};
            int dy[4] = {1, 0, -1, 0};
    
            int count = 0;
            int maxVal = 0;
    
            for (auto [query, index] : queryIndex) {
                while (!pq.empty() && pq.top().first < query) {
                    auto [val, pos] = pq.top();
                    pq.pop();
                    int x = pos.first, y = pos.second;
                    count++;
    
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                            pq.push({grid[nx][ny], {nx, ny}});
                            visited[nx][ny] = true;
                        }
                    }
                }
                result[index] = count;
            }
            return result;
        }
    };
    