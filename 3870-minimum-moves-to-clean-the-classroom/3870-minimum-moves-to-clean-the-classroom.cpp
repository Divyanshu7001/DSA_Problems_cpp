// minimum moves / shortest path..bfs
// simple dfs of row & column check wont work
// state def=> [row][col][energy][litters collected]
// now litteres collected cant be vector or list..has to be integer
// so for ever row & col of litter...we will manage a bit
// if that is collected..set that corresponding bit to 1 => bitmask

// total of a 10 bit value to be kept as litters value

// for the state...get a struct to store the state in the queue => bfs
class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    struct state {
        int row;
        int col;
        int energyLeft;
        int collecLittersMask;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size(), n = classroom[0].size();

        int maxEnergy = energy;

        int litterBit[20][20];
        int litterCount = 0;
        int startR = 0, startC = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                litterBit[r][c] = -1;
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (classroom[r][c] == 'L') {
                    litterBit[r][c] = litterCount;
                    litterCount++;
                }
            }
        }

        int allCollected = (1 << litterCount) - 1;

        if (allCollected == 0)
            return 0;

        queue<state> que;
        que.push({startR, startC, maxEnergy, 0});

        VVVVB visited(m,
                      VVVB(n, VVB(maxEnergy + 1, VB((1 << litterCount), false))));
        visited[startR][startC][maxEnergy][0] = true;

        int moves = 0;
        while (!que.empty()) {
            int currSize = que.size();
            while (currSize--) {
                state curr = que.front();
                que.pop();

                if (curr.collecLittersMask == allCollected)
                    return moves;

                if (curr.energyLeft == 0)
                    continue;

                for (auto& dir : directions) {
                    int nextR = curr.row + dir[0], nextC = curr.col + dir[1];

                    if (nextR < 0 || nextR >= m || nextC < 0 || nextC >= n)
                        continue;

                    char cell = classroom[nextR][nextC];
                    if (cell == 'X')
                        continue;

                    int nextEnergy = curr.energyLeft - 1;
                    if (cell == 'R')
                        nextEnergy = maxEnergy;

                    int nextcollecLittersMask = curr.collecLittersMask;
                    if (cell == 'L')
                        nextcollecLittersMask |= (1 << litterBit[nextR][nextC]);

                    if (!visited[nextR][nextC][nextEnergy]
                                [nextcollecLittersMask]) {
                        visited[nextR][nextC][nextEnergy]
                               [nextcollecLittersMask] = true;
                        que.push(
                            {nextR, nextC, nextEnergy, nextcollecLittersMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};