class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        sort(capacity.begin(), capacity.end(), greater());

        int i = 0, target = accumulate(apple.begin(), apple.end(), 0),
            current = capacity[0], count = 1;

        while (i < capacity.size()) {
            if (current >= target) {
                return count;
            }
            i++;
            current += capacity[i];
            count++;
        }

        return count;
    }
};