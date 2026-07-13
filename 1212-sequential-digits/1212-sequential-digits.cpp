class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> que;
        for (int i = 1; i <= 8; i++) {
            que.push(i);
        }

        vector<int> res;
        while (!que.empty()) {
            int temp = que.front();
            que.pop();
            if (temp > high)
                break;
            if (temp >= low && temp <= high) {
                res.push_back(temp);
            }

            int last_dig = temp % 10;
            if (last_dig + 1 <= 9) {
                que.push(temp * 10 + (last_dig + 1));
            }
        }
        return res;
    }
};