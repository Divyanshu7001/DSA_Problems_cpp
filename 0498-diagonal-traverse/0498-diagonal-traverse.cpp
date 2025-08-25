class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        bool dir = 1; // 1=> up & 0=> down traversal
        int i = 0, r = 0, c = 0;
        vector<int> ans(m * n);
        while (r < m && c < n) {
            ans[i] = mat[r][c];
            i++;
            int newr, newc;
            if (dir == 1) {
                newr = r - 1;
                newc = c + 1;
            } else {
                newr = r + 1;
                newc = c - 1;
            }

            if (newr >= 0 && newr < m && newc >= 0 && newc < n) {
                r = newr, c = newc;
            } else {
                if (dir == 1) {
                    if (c < n - 1)
                        c++;
                    else
                        r++;
                } else {
                    if (r < m - 1)
                        r++;
                    else
                        c++;
                }
                dir = !dir;
            }
        }
        return ans;
    }
};