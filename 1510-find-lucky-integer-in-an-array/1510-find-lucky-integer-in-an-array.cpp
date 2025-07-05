class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> store;
        int lucky = -1;
        for (int num : arr) {
            store[num]++;
        }

        for (auto& pair : store) {
            if (pair.first == pair.second && pair.first > lucky)
                lucky = pair.first;
        }

        return lucky;
    }
};