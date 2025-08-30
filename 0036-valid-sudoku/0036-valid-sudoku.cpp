class Solution {
public:
    bool isValidRowsAndCols(vector<vector<char>>& board) {
        int n = board.size();

        // check rows
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                if (mp.find(board[i][j]) == mp.end())
                    mp[board[i][j]]++;
                else
                    return false;
            }
        }

        // check columns
        for (int j = 0; j < n; j++) {
            unordered_map<char, int> mp;
            for (int i = 0; i < n; i++) {
                if (board[i][j] == '.') continue;
                if (mp.find(board[i][j]) == mp.end())
                    mp[board[i][j]]++;
                else
                    return false;
            }
        }

        return true;
    }

    bool isValidSubbox(vector<vector<char>>& subBoard) {
        int n = subBoard.size();
        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (subBoard[i][j] == '.') continue;
                if (mp.find(subBoard[i][j]) == mp.end())
                    mp[subBoard[i][j]]++;
                else
                    return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool result = isValidRowsAndCols(board);
        if (!result) return false;

        vector<int> ranges = {0, 3, 6};
        for (auto range : ranges) {
            int j = range;
            int i = 0;
            while (i < 9) {
                vector<vector<char>> subGrid;
                for (int initial = i; initial < i + 3; initial++) {
                    vector<char> rowWiseVector;
                    for (int latter = j; latter < j + 3; latter++) {
                        rowWiseVector.push_back(board[initial][latter]);
                    }
                    subGrid.push_back(rowWiseVector);
                }
                result = isValidSubbox(subGrid);
                if (!result) return false;
                i += 3;
            }
        }

        return true;
    }
};
