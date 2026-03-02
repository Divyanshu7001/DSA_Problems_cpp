class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int swapsNeeded = 0, n = grid.size();
        vector<int> endZeros(n, 0);
        for (int i = 0; i < n; i++) {
            int count = 0, j = n - 1; // start from end to count 0s
            while (j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }
            endZeros[i] = count;
        }
        
        int steps = 0;
        for (int i = 0; i < n; i++) {
            int need = n - i - 1; // how many zeros it needs
            int j = i;            // if the row itself already has the needed 0s

            while (j < n && endZeros[j] < need)
                j++;

            if (j == n)
                return -1;
            steps += j - i;

            while (j > i) {
                swap(endZeros[j], endZeros[j - 1]);
                j--;
            }
        }
        return steps;
    }
};