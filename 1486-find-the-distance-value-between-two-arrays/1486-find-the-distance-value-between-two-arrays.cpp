class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr2.size(), count = 0;
        for (int& num : arr1) {
            bool breaking = false;
            for (int i = 0; i < n; i++) {
                if (abs(num - arr2[i]) <= d) {
                    breaking = true;
                    break;
                }
            }
            if (!breaking)
                count++;
        }

        return count;
    }
};