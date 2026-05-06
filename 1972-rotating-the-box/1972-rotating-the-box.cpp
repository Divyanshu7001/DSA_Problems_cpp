class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();

        vector<vector<char>> res(n, vector<char>(m, '.'));
        for (int i = 0; i < m; i++) {
            int blankSpace = -1;
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    res[j][m - i - 1] = '*';
                    blankSpace = -1;
                } else if (boxGrid[i][j] == '.') {
                    blankSpace = max(blankSpace, j);
                } else {
                    if (blankSpace == -1) {
                        res[j][m - i - 1] = '#';
                    } else {
                        res[blankSpace][m - i - 1] = '#';
                        boxGrid[i][j] = '.';
                        bool foundSpace = false;
                        while (blankSpace) {
                            blankSpace--;
                            if (boxGrid[i][blankSpace] == '.') {
                                foundSpace = true;
                                break;
                            }
                        }
                        if (!foundSpace)
                            break;
                    }
                }
            }
        }

        return res;
    }
};