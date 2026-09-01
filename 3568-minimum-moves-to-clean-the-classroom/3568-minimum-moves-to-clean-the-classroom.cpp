class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        pair<int, int> start;
        map<pair<int, int>, int> litterId;

        int littercnt = 0;

        // Find starting position and assign IDs to litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    start = {i, j};
                }

                if (classroom[i][j] == 'L') {
                    litterId[{i, j}] = littercnt++;
                }
            }
        }

        // Mask when all litter is collected
        int allMask = (1 << littercnt) - 1;

        // {row, col, energy, mask, moves}
        queue<array<int, 5>> q;

        q.push({
            start.first,
            start.second,
            energy,
            0,
            0
        });

        bool visited[20][20][51][1024] = {};

        visited[start.first][start.second][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            // Get current state
            auto [r, c, currEnergy, mask, moves] = q.front();
            q.pop();

            // All litter collected
            if (mask == allMask) {
                return moves;
            }

            // No energy left
            if (currEnergy == 0) {
                continue;
            }

            // Try 4 directions
            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n) {
                    continue;
                }

                // Obstacle
                if (classroom[nr][nc] == 'X') {
                    continue;
                }

                // Moving costs 1 energy
                int newEnergy = currEnergy - 1;

                // Reset energy at R
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                // Update litter mask
                int newMask = mask;

                if (classroom[nr][nc] == 'L') {

                    int id = litterId[{nr, nc}];

                    newMask = mask | (1 << id);
                }

                // Already visited this exact state
                if (visited[nr][nc][newEnergy][newMask]) {
                    continue;
                }

                visited[nr][nc][newEnergy][newMask] = true;

                // Add next state
                q.push({
                    nr,
                    nc,
                    newEnergy,
                    newMask,
                    moves + 1
                });
            }
        }

        return -1;
    }
};