class Solution {
public:
    vector<int> result;

    void dfs(int curr, int n) {
        if (curr > n)
            return;
        result.push_back(curr);

        for (int i = 0; i <= 9; i++) {
            int next = curr * 10 + i;
            if (next > n)
                return;
            dfs(next, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++) {
            dfs(i, n);
        }

        return result;
    }
};